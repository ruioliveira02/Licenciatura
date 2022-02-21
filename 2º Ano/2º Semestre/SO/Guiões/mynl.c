#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

/*

TODO: Modify to read more than 1 byte at a time

*/
ssize_t readln(int fd, char* line, size_t size) {
    ssize_t i = 0;
    int readBytes = 0;
    while(i < size && (readBytes = read(fd, line + i, 1)) > 0) {
        i++;
        if(line[i - 1] == '\n')
            break;

    }
    line[i] = '\0';
    return i;
}


int intToString(int number, char* buffer) {
    if(number == 0) {
        buffer[0] = '0';
        buffer[1] = '\0';
        return 1;
    } else {
        int i = 0;

        while(number > 0) {
            buffer[i++] = (number % 10) + '0';
            number /= 10;
        }

        for(int j = i - 1; j >= i / 2; j--) {
            char temp = buffer[j];
            buffer[j] = buffer[i - 1 - j];
            buffer[i - 1 - j] = temp;
        }
            

        buffer[i] = '\0';
        return i;
    }
}

int main(int argc, char* argv[]) {
    
    //Wrong number of arguments
    if(argc != 1) {
        return 1;
    }
    
    /*int input = open(STDIN_FILENO, O_RDONLY);
    if(input < 0) {
        perror("open input file failed");
        return 1;
    }*/

    char buffer[1024];
    int bytesRead = 0;
    int line = 1;
    while((bytesRead = readln(STDIN_FILENO, buffer, 1024)) > 0) {
        char lineBuffer[100];
        int size = intToString(line, lineBuffer);
        write(STDOUT_FILENO, &lineBuffer, size);
        write(STDOUT_FILENO, " ", 1);
        write(STDOUT_FILENO, &buffer, bytesRead);
        line++;
    }


    //close(input);
    
    return 0;
}