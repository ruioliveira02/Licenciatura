#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

/**
 * @brief Reads the next line in file to the given 
 * 
 * @param fd        The file descriptor
 * @param line      The buffer in which to store the line
 * @param size      The maximum number of bytes to read
 * 
 * @return ssize_t  The number of bytes read 
 */
ssize_t readln(int fd, char* line, size_t size) {
    ssize_t bytesRead = read(fd, line, size);

    for(int i = 0; i < bytesRead - 1; i++) {
        if(line[i] == '\n') {
            lseek(fd, -(bytesRead - i + 1), SEEK_CUR);
            return i;
        }       
    }

    return bytesRead;
}

int main(int argc, char* argv[]) {
    
    //Wrong number of arguments
    if(argc != 3) {
        return 1;
    }
    
    int input = open(argv[1], O_RDONLY);
    if(input < 0) {
        perror("open input file failed");
        return 1;
    }

    int output = open(argv[2], O_CREAT | O_TRUNC | O_WRONLY, 0640);
    if(output < 0) {
        perror("create output file failed");
        return 1;
    }


    char buffer[1024];
    int bytesRead = 0;
    while((bytesRead = read(input, &buffer, 1024)) > 0) {
        write(output, &buffer, bytesRead);
    }


    close(input);
    close(output);
    
    return 0;
}