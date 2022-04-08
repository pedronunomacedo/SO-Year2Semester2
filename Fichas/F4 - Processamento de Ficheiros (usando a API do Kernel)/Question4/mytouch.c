#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_SIZE 64

void output_permissons(__mode_t m) {
    putchar( m & S_IRUSR ? 'r' : '-');
    putchar( m & S_IWUSR ? 'w' : '-');
    putchar( m & S_IXUSR ? 'x' : '-');
    putchar( m & S_IRGRP ? 'r' : '-');
    putchar( m & S_IWGRP ? 'w' : '-');
    putchar( m & S_IXGRP ? 'x' : '-');
    putchar( m & S_IROTH ? 'r' : '-');
    putchar( m & S_IWOTH ? 'w' : '-');
    putchar( m & S_IXOTH ? 'x' : '-');
    putchar('\n');
}

int main(int argc, char* argv[]) {
    char* f = (char*)malloc(MAX_STR_SIZE * sizeof(char)); // Alocatting memory to store the string variable
    strcpy(f, argv[1]); 
    FILE* file;
    struct stat fs; // To change the permissons of the file received
    int r;

    if (argc != 2) {
        printf("ERROR: Give only the name of one file!\n");
        return EXIT_FAILURE;
    }

    file = fopen(f, "w");
    
    r = stat(f, &fs);

    /*if (chmod(f, 644) == -1 || r == -1) {
        printf("ERROR: Change denied\n");
        return EXIT_FAILURE;
    }*/
    
    puts("Current permissons: ");
    output_permissons(fs.st_mode);

    puts("Set group and their write permissons\n");
    r = chmod( f, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH); // The permisson is not giving me write!
    if (r != 0) {
        printf("Unable to change the permissons of the file '%s'", f);
        return EXIT_FAILURE;
    }

    puts("Updated permissons: ");
    stat(f, &fs);
    output_permissons(fs.st_mode);

    return EXIT_SUCCESS;    
}