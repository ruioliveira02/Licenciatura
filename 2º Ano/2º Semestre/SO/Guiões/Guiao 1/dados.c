#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#include "error.h"

struct dados {
    char nome[100];
    int idade;
};


/**
 * @brief               Appends the given data to a binary file
 * 
 * @param fileName      The name of the file
 * @param data          The data to append to the file
 * @param size          The size (in bytes) of the struct to save
 * 
 * @return ErrorCode    #NO_ERROR on success, #FILE_OPENING_ERROR if the file 
 *                      cannot be opened
 */
ErrorCode appendToFile(char* fileName, void* data, size_t size) {
    int fileDescriptor = open(fileName, O_CREAT | O_APPEND | O_WRONLY, 0660);

    if(fileDescriptor < 0) {
        return FILE_OPENING_ERROR;
    }

    write(fileDescriptor, data, size);

    close(fileDescriptor);

    return NO_ERROR;
}

/**
 * @brief                   Updates the given value stored in a file
 * 
 *                          If the value does not exist, nothing is done
 * 
 * @param fileName          The name of the file
 * @param data              The data to replace the original value with
 * @param size              The size of a data block
 * @param compareFunction   The function used to check if two data blocks are equal
 * 
 * @return ErrorCode        #NO_ERROR on success, #FILE_OPENING_ERROR if the file 
 *                          cannot be opened
 */
ErrorCode updateValue(char* fileName, void* data, size_t size, int (*compareFunction)(void*, void*)) {
    int fileDescriptor = open(fileName, O_RDWR, 0660);

    if(fileDescriptor < 0) {
        return FILE_OPENING_ERROR;
    }

    char buffer[size];

    int bytesRead = 0;

    while((bytesRead = read(fileDescriptor, buffer, size)) > 0) {
        //Checks if this is the value we want to replace:
        //The passed function returns 0 if they are equal
        if(!compareFunction(buffer, data)) {
            //Revert to the first byte of the value to replace
            lseek(fileDescriptor, -size, SEEK_CUR);

            //Overwrite value
            write(fileDescriptor, data, size);

            //Only allow 1 value to change
            break;
        }
    }

    close(fileDescriptor);

    return NO_ERROR;
}