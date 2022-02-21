/**
 * @file error.c
 *
 * @brief File implementing the error handling for the application
 * 
 */

#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#include "error.h"

/**
 * @brief           Returns the current time as a string
 * 
 *                  The string is malloc'ed and must be freed
 * 
 * @return char*    The requested string
 */
char* getTimeString() {
    time_t rawtime;
    struct tm * timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    return asctime(timeinfo);
}


/**
 * @brief           Logs the given error with a time stamp to the standard error
 * 
 * @param error     The error code
 * @param message   The message to log
 */
void logError(ErrorCode code, char message[]) {
    char buffer[500] = "[";
    //Variable used to store the code as a string
    char codeBuffer[20];
    itoa(code, codeBuffer);

    char* timeString = getTimeString();

    strcat(buffer, timeString);
    strcat(buffer, "] ERROR: ");
    strcat(buffer, codeBuffer);
    strcat(buffer, message);
    strcat(buffer, "\n");

    write(STDERR_FILENO, buffer, strlen(buffer));

    free(timeString);
}

/**
 * @brief           Logs the given message with a time stamp to the standard output
 * 
 * @param message   The message to log
 */
void log(char message[]) {
    char buffer[500] = "[";


    char* timeString = getTimeString();

    strcat(buffer, timeString);
    strcat(buffer, "] ");
    strcat(buffer, message);
    strcat(buffer, "\n");

    write(STDOUT_FILENO, buffer, strlen(buffer));

    free(timeString);
}