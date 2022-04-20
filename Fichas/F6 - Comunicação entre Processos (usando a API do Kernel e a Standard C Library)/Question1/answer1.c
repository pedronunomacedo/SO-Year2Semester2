#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_STR_SIZE 64

#define READ_END 0
#define WRITE_END 1

#define LINESIZE 256

int main(int argc, char* argv[]) {
    char* f = (char*)malloc(MAX_STR_SIZE * sizeof(char)); // Alocatting memory to store the string variable
    strcpy(f, argv[1]); // Copy the name of the file to the variable file

    FILE* file;
    file = fopen(f, "r");
    char ch;
    int nbytes, fd[2];
    pid_t pid;
    char line[LINESIZE];

    // A pipe can be considered has a communication channel that connects two processes and allows 
    // an undirected information flux (half duplex). The pipe is represented by an array of integers
    // of two positions (position 0 - Read; 1 position 1 - Write)
    if (pipe(fd) < 0) {
        perror("pipe error");
        exit(EXIT_FAILURE);
    }

    if ((pid = fork()) < 0) {
        perror("fork error");
        exit(EXIT_FAILURE);
    }
    else if (pid > 0) {
        /* parent */

        close(fd[READ_END]);
        ch = fgetc(file);
        while (ch != EOF){
            if ((nbytes = write(fd[WRITE_END], &ch, 1)) < 0) {
                fprintf(stderr, "Unable to write to pipe: %s\n", strerror(errno));
            }
            ch = fgetc(file);
        }

        close(fd[WRITE_END]);

        /* wait for child and exit */
        if ( waitpid(pid, NULL, 0) < 0) {
            fprintf(stderr, "Cannot wait for child: %s\n", strerror(errno));
        }
        exit(EXIT_SUCCESS);
    }
    else {
        /* child */
        close(fd[WRITE_END]);

        while ((nbytes = read(fd[READ_END], &ch, 1)) > 0) {
            /* write message from parent */
            write(STDOUT_FILENO, &ch, 1);
        }
        printf("\n");
        close(fd[READ_END]);
        /* exit gracefully */
        exit(EXIT_SUCCESS);
    }


    return 0;

}
