// Answer 4
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STR_SIZE 64

int main(int argc, char* argv[]) {
    char* arg = (char*)malloc((sizeof(argv[1])) * sizeof(char));
    char* file = (char*)malloc((sizeof(argv[2])) * sizeof(char));

    FILE* f;
    int display;

    if (argc == 2) { // In the case we only want to see the content of the file
        strcpy(file, argv[1]); // name of the file
    }
    else if (argc == 3) {
        strcpy(arg, argv[1]); // name of the operation
        strcpy(file, argv[2]); // name of the file
    }

    f = fopen(file, "r");
    if (strcmp(arg, "-u") == 0 && argc == 3) {
        // Transform all the letters in uppercase letters
        while (1) {
            display = fgetc(f);
            if (feof(f)) break;
            printf("%c", toupper(display));
        }
    }
    else if (strcmp(arg, "-l") == 0 && argc == 3) {
        // Transform all the letters in lowercase letters
        while (1) {
            display = fgetc(f);
            if (feof(f)) break;
            printf("%c", tolower(display));
        }
    }
    else if (argc == 2) {
        // Print the file as it is
        while (1) {
            display = fgetc(f);
            if (feof(f)) break;
            printf("%c", display);
        }
    }
    fclose(f);
    
    return EXIT_SUCCESS;
}