#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // USed to print the date

int main(int argc, char* argv[]) {

    int numFile = 1;

    while (numFile < argc) {
        struct stat info;
        
        if (lstat(argv[numFile], &info) == -1) {
            fprintf(stderr, "fsize: Can’t stat %s\n", argv[numFile]);
            return EXIT_FAILURE;
        }

        printf("%s size: %d bytes, %d disk_blocks, %s last update date, owner %ju\n",
            argv[numFile], (int)info.st_size, (int)info.st_blocks, ctime(&info.st_mtime), (__uintmax_t)info.st_uid);
            printf("\n");
        numFile++; // Next file
    }

    return EXIT_SUCCESS;
}