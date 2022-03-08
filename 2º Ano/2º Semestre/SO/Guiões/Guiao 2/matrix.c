#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

/**
 * @brief Relative path to the matrix file
 * 
 */
#define MATRIX_PATH "matrix.mat"

/**
 * @brief           Populates a matrix with random values
 * 
 * @param rows      The number of rows in the matrix
 * @param collumns  The number of collumns in the matrix
 * @param matrix    The matrix to populate
 */
void generateRandomMatrix(int rows, int collumns, int matrix[rows][collumns]) {

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < collumns; j++) {
            matrix[i][j] = 69;//rand();
        }
    }
}

/**
 * @brief                   Searches a row of the matrix for the presence of 
 *                          the given value
 * 
 * @param fileDescriptor    The file descriptor storing the matrix
 * @param rowIndex          The index (0 based) of the row to search
 * @param collumns          The number of collumns in a matrix row
 * @param value             The value to search for in the matrix
 * @return int              1 if the value is found, 0 otherwise
 */
int searchForRow(int fileDescriptor, int rowIndex, int collumns, int value) {
    int row[collumns];
    lseek(fileDescriptor, rowIndex * sizeof(int) * collumns, SEEK_SET);
    read(fileDescriptor, row, sizeof(int) * collumns);

    int result = 0;

    for(int i = 0; i < collumns; i++) {
        if(row[i] == value) {
            result = 1;
            break;
        }
    }

    return result;
}

/**
 * @brief                   Searches the matrix for the given value
 * 
 * @param fileDescriptor    The open file descriptor containing the matrix
 * @param rows              The number of rows in the matrix
 * @param collumns          The number of collumns in the matrix
 * @param value             The value to search for
 */
void searchMatrix(int fileDescriptor, int rows, int collumns, int value) {
    int found[rows];
    int pids[rows];
    int pid;
    for(int i = 0; i < rows; i++) {
        if((pid = fork()) == 0) {
            dup(fileDescriptor);
            pids[i] = pid;
            int result = searchForRow(fileDescriptor, i, collumns, value);
            close(fileDescriptor);
            _exit(result);
        } //TODO:: Error handling
    }

    for(int i = 0; i < rows; i++) {
        int status;
        waitpid(pids[i], &status, 0);

        int res = WEXITSTATUS(status);
        if(res == 0 || res == 1)
            found[i] = res;
        //TODO:: Error handling
    }

    for(int i = 0; i < rows; i++) {
        if(found[i])
            printf("Row %d\n", i);
    }
}

int main(int argc, char* argv[]) {

    while(1) {
        int rows, cols, val;
        scanf("%d %d %d\n", &rows, &cols, &val);
        printf("%d %d %d\n", rows, cols, val);
        int matrix[rows][cols];
        int fileDescriptor = open(MATRIX_PATH, O_CREAT | O_TRUNC | O_RDWR, 0660);
        generateRandomMatrix(rows, cols, matrix);
        write(fileDescriptor, matrix, sizeof(matrix));
        searchMatrix(fileDescriptor, rows, cols, val);
        scanf("%d\n", &val);
        close(fileDescriptor);
        if(!val)
            break;
    }

    return 0;
}