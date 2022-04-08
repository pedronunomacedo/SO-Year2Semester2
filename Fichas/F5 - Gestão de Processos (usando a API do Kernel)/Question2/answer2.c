#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc, char* argv[]) {
    for (int i = 0; i < 4; i++) {
        fork();
        pid_t pid = getpid();
        printf("Fork %d: %d\n", i, pid);
    }
    sleep(1);
    
    return EXIT_SUCCESS;
}