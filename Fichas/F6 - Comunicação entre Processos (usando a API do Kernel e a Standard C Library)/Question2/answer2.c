#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define READ_END 0
#define WRITE_END 1

char* cmd1[] = {"ls", "-l", NULL}; // Writes to 
char* cmd2[] = {"wc", "-l", NULL};

int main (int argc, char* argv[]) {
    int fd[2];
    pid_t pid;

    if (pipe(fd) < 0) {
        fprintf(stderr, "ERROR: pipe failed\n");
        return EXIT_FAILURE;
        /* pipe error */
    }

    if ((pid = fork()) < 0) {
        /* fork error */
        fprintf(stderr, "ERROR: fork failed\n");
        return EXIT_FAILURE;
    }

    if (pid > 0) {
        /* parent process */
        close(fd[READ_END]);
        dup2(fd[WRITE_END], STDOUT_FILENO); // stdout to pipe
        close(fd[WRITE_END]);
        // parent writes to the pipe
        if (execvp(cmd1[0], cmd1) < 0) { // Execute the command passed and substitutes the parent process by the command given
            /* exec error */
            fprintf(stderr, "ERROR: exec failed\n");
            return EXIT_FAILURE;
        }
    } else {
        /* child process */
        close(fd[WRITE_END]);
        dup2(fd[READ_END], STDIN_FILENO); // stdin from pipe
        close(fd[READ_END]);
        dup2()
        if (execvp(cmd2[0], cmd2) < 0) {
            /* exec error */
        }
    }
}

// What this program does is basically:

    // -> The child executes the command "wc -l"
        // . This command is used to count the umber of lines, words, ... of a text file
            // - If the file was not specified, wich is the case, then it will read the text in the STDIN
        // . The option "-l" actives the line couting, wich will be printed in the STDOUT
    // -> The parent executes the command "ls -l"
    // -> The program is configured in order to the STDOUT of the command "ls -l" will be connected to the STDIN of the "wc -l"
        // . So, the program in general will pront the number of lines in the output of the command "wc -l"
        // . It will be equivalent executing the commands using pipes in the shell, i.e., "ls -l | wc -l"
// To get this, we need to:
    // -> (FINISH THIS! Files of the teacher in github)