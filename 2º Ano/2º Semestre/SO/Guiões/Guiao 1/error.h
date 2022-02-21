/**
 * @file  error.h                       
 *
 * @brief File declaring the API for error handling in the application
 * 
 */

#ifndef _ERROR_H_

/**
 * @brief Include guard
 */
#define _ERROR_H_

/**
 * @brief Logs the error to standard error and returns its code
 *
 */
#define THROW_ERROR(code, message) logError(code, message); \
                                   return code

/**
 * @brief Enum used to store error codes and their respective meaning
 * 
 */
typedef enum error_Codes {
    NO_ERROR           = 0, ///< No error has occured
    FILE_OPENING_ERROR = 1  ///< Error opening file
} ErrorCode;


void logError(ErrorCode, char[]);

void log(char[]);

#endif