#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    
    //Wrong number of arguments
    if(argc != 2) {
        return 1;
    }
    
    int input = open(argv[1], O_RDONLY);
    if(input < 0) {
        perror("open input file failed");
        return 1;
    }

    char buffer[1024];
    int bytesRead = 0;
    while((bytesRead = read(input, &buffer, 1024)) > 0) {
        write(STDOUT_FILENO, &buffer, bytesRead);
    }


    close(input);
    
    return 0;
}