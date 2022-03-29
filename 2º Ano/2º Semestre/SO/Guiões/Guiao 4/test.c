#include <unistd.h>
#include <fcntl.h>

int main() {
    int ifd = open("entrada.txt", O_RDONLY);
    int ofd = open("saida.txt", O_CREAT | O_TRUNC | O_WRONLY, 0640);
    int efd = open("erros.txt", O_CREAT | O_TRUNC | O_WRONLY, 0640);

    dup2(ifd, STDIN_FILENO);
    close(ifd);

    dup2(ofd, STDOUT_FILENO);
    close(ofd);

    dup2(efd, STDERR_FILENO);
    close(efd);

    if(!fork()) {
        execlp("wc", "wc", NULL);
    }

    return 0;
}