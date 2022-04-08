// Answer3
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
    char* p = (char*)malloc(sizeof(argc) * sizeof(char));
    
    for (int i = 1; i < argc; i++) {
        char* p = (char*)malloc(sizeof(argv[i]) * sizeof(char));
        strcpy(p, argv[i]);

        FILE* f;
        int display;

        f = fopen(p, "r");
        while (1) {
            display = fgetc(f);

            if (feof(f)) break;

            printf("%c", display);
        }

        fclose(f);
    }

    return 0;
}