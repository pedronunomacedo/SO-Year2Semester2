#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int next_block_size(int count, int buffer_size) {
    return (count >= buffer_size)? buffer_size: count % buffer_size;
}

int main(int argc, char* argv[]) {
    int numARGC = argc;
    int fd;

    /* check if file can be opened and is readable */
    int numFile = 1;
    int error = 0;
    while (numARGC > 1) {
        int fd = open(argv[numFile], O_RDONLY);
        if (fd == -1) {
            error = 1; // Found a file that can't be open
            printf("error: cannot open %s\n", argv[numFile]);

        }
        numARGC--;
        numFile++; // Next file to check
    }
    if (error == 1) return EXIT_FAILURE;
    numARGC = argc; // Reset the number of files given
    numFile = 1; // Reset the number of file to be checked

    while (numARGC > 1) {
        /* get the file size */
        struct stat info;
        int ret = lstat(argv[numFile], &info);
        if (ret == -1) {
            printf("error: cannot stat %s\n", argv[numFile]);
            return EXIT_FAILURE;
        }

        /* print the contents in blocks */
        int fd = open(argv[numFile], O_RDONLY);
        printf("%s\n", argv[numFile]);
        int count = info.st_size;
        char buffer[BUFFER_SIZE];
        while (count != 0) {
            int bytesin = read(fd, buffer, next_block_size(count, BUFFER_SIZE));
            count -= bytesin;
            write(STDOUT_FILENO, buffer, bytesin);
        }
        close(fd);
        numARGC--;
        numFile++;

        printf("\n");
    }

    return EXIT_SUCCESS;
}