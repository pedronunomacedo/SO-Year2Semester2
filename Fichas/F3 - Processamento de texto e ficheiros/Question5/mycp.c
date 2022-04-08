// Answer 5
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STR_SIZE 64

int main(int argc, char* argv[]) {
    char* f1 = (char*)malloc(sizeof(argv[1]) * sizeof(char));
    char* f2 = (char*)malloc(sizeof(argv[2]) * sizeof(char));

    strcpy(f1, argv[1]); // Name of the first file
    strcpy(f2, argv[2]); // Name of the second file

    FILE* file1; FILE* file2; FILE* file3;
    char ch;

    file1 = fopen(f1, "r");
    file2 = fopen(f2, "w");
    if (file2 == NULL) { // If file2 doesn't exist
        fclose(file2); // Close the file2 in order to open it again in "writing" mode (wb)
        file3 = fopen(f2, "wb"); // Create the file3 another pointer to the "same" file

        while ((ch = fgetc(file1)) != EOF) {
            fputc(ch, file3); // Put one character of file1 in file2
        }
        fclose(file3);
    }
    else { // File 2 already exists (Overwrite it)
        fclose(file2);
        file2 = fopen(f2, "w+"); // Open the existing file2 to overwrite it

        while((ch = fgetc(file1)) != EOF) {
            fputc(ch, file2);
        }
        fclose(file2);
    }
    fclose(file1);

    return EXIT_SUCCESS;
}