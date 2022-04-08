#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    char cwd[256]; // Current Working Directory

    if (getcwd(cwd, sizeof(cwd)) == NULL) { // Returns NULL when an error was found
        perror("ERROR: getcwd() error\n");
    }
    else {
        printf("Current woking directory is: %s\n", cwd);
    }
}