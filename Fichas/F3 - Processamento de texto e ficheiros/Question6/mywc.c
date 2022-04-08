// Answer6
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STR_SIZE 64

int main(int argc, char* argv[]) {
    char* option = (char*)malloc(MAX_STR_SIZE * sizeof(char));
    char* f = (char*)malloc(MAX_STR_SIZE * sizeof(char));

    FILE* file;
    int res = 0;
    int ch;
    
    if (argc == 3) { // If an option was given
        strcpy(option, argv[1]); // option string
        strcpy(f, argv[2]); // file string

        file = fopen(f, "r");
        if (strcmp(option, "-w") == 0) { // If (option == "-w")
            ch = fgetc(file);
            if (ch != EOF) res++; // In the case that the file consists of only one word (one word will not have a space after).
                                  // This also increments res if it as a word in beggining. If in the beggining it reaches the end of the file, it's beacuse the file has no word (empty file).
            while (ch != EOF) { // While it has content on the file to read
                if (ch == ' ') res++;
                ch = fgetc(file);
            }
        }
        else if (strcmp(option, "-l") == 0) {
            ch = fgetc(file);
            while (ch != EOF) {
                if (ch == '\n') res++;
                ch = fgetc(file);
            }
        }
        else if (strcmp(option, "-c") == 0) {
            ch = fgetc(file);
            while (ch != EOF) {
                res++;
                ch = fgetc(file);
            }
        }
        fclose(file);
        printf("%d\n", res);

        return EXIT_SUCCESS;
    }
    
    strcpy(f, argv[1]);
    file = fopen(f, "r");
    ch = fgetc(file);
    while (ch != EOF) {
        res++;
        ch = fgetc(file);
    }   
    fclose(file); 

    printf("%d\n", res);

    return EXIT_SUCCESS;
}