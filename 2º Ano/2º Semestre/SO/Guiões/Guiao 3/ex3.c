#include <unistd.h>
#include<sys/wait.h>

int main(int argc, char* argv[]) {
    for(int i = 1; i < argc; i++) {
        if(!fork()) {
            if(execlp(argv[i], (char*[]){argv[i], NULL}) < 0)
                perror("exec");

            _exit(1);
        }
    }

    for(int i = 1; i < argc; i++) {
        int status;
        wait(&status);

        if(status != 0)
            perror("ERROR\n");
    }

    return 0;
}