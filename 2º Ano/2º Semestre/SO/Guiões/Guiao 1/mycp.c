#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

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