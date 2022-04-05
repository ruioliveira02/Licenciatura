#include <unistd.h>


int main() {

    int pipes1[2];
    int pipes2[2];
    if(pipe(pipes1) || pipe(pipes2)) {
        perror("Cannot open pipes");
        __exit(0);
    }

    if(!fork()) {
        close(pipes1[0]);
        close(pipes2[0]);
        close(pipes2[1]);
        dup2(pipes1[1], STDOUT_FILENO);
        execl("grep", "grep", "-v", "^#", "/etc/passwd", NULL);
    }

    if(!fork()) {
        close(pipes1[1]);
        close(pipes2[0]);
        dup2(STDIN_FILENO, pipes1[0]);
        dup2(pipes2[0], STDOUT_FILENO);
        execl("cut", "cut", "-f7" "-d:", NULL);
    }

    if(!fork()) {
        close(pipes1[0]);
        close(pipes1[1]);
        close(pipes2[1]);
        dup2(STDIN_FILENO, pipes2[0]);
        execl("uniq", "uniq", NULL);
    }

    return 0;
}