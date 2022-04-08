#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STR_SIZE 64

int main(int argc, char* argv[]) {
    char* p = (char*)malloc(MAX_STR_SIZE * sizeof(char)); // Alocatting memory to store the string variable
    char* res = (char*)malloc(MAX_STR_SIZE * sizeof(char)); // Alocatting memory to store the resultant string

    strcpy(p, argv[1]);
    
    for (size_t i = 0; i < strlen(p); i++) {
        res[i] = tolower(p[i]);
    }

    printf("Result: %s\n", res);

    return EXIT_SUCCESS;
}