#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc, char* argv[]) {
    pid_t pid;

    /* fork a child process */
    fork();
    pid = getpid();
    printf("1º Fork: %d\n", pid);

    /* fork another child process */
    fork();
    pid = getpid();
    printf("2º Fork: %d\n", pid);

    /* and fork another */
    fork();
    pid = getpid();
    printf("3º Fork: %d\n", pid);

    return EXIT_SUCCESS;
}