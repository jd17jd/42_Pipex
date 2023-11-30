#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main (int argc, char *argv[])
{
    int fd[2];
    if (pipe(fd) == -1) {
        return (1);
    }

    int id1 = fork();
    if (id1 < 0) {
        perror("Error al crear la tuberia");
        return (2);
    }

    if (id1 == 0) {
        //Child process 1 (ping)
        dup2(fd[1], STDOUT_FILENO); //Duplica el primer fd al segundo, cerrando el segundo 
        close(fd[0]);
        close(fd[1]); //Se queda abierto aunque lo acabemos de duplicar, no solo  mueva el fd sino que lo duplica
        execlp("ping", "ping", "-c", "5", "google.com", NULL); //ejecuta el comando "ping -c 5 google.com" desde el proceso hijo
    }

    int id2 = fork();
    if (id1 < 0) {
        perror("Error al crear la tuberia");
        return (3);
    }

    if (id2 == 0) {
        //Child process 1 (ping)
        dup2(fd[0], STDIN_FILENO); //Duplica el primer fd al segundo, cerrando el segundo 
        close(fd[0]);
        close(fd[1]); //Se queda abierto aunque lo acabemos de duplicar, no solo  mueva el fd sino que lo duplica
        execlp("grep", "grep", "rtt", NULL);

    }

    close(fd[0]);
    close(fd[1]);

    waitpid(id1, NULL, 0);
    waitpid(id2, NULL, 0);

    return (0);
}
