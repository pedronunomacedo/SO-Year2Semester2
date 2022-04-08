#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_STR_SIZE 64

void output_permissons(__mode_t m) {
    if (S_ISREG(m)) {
        putchar('-');
    }
    else if (S_ISDIR(m)) {
        putchar('d');
    }
    putchar( m & S_IRUSR ? 'r' : '-');
    putchar( m & S_IWUSR ? 'w' : '-');
    putchar( m & S_IXUSR ? 'x' : '-');
    putchar( m & S_IRGRP ? 'r' : '-');
    putchar( m & S_IWGRP ? 'w' : '-');
    putchar( m & S_IXGRP ? 'x' : '-');
    putchar( m & S_IROTH ? 'r' : '-');
    putchar( m & S_IWOTH ? 'w' : '-');
    putchar( m & S_IXOTH ? 'x' : '-');
    putchar(' ');
}

int main(int argc, char* argv[]) {
    struct stat fs;

    if (stat())
}