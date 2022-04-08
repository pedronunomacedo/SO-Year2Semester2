#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STR_SIZE 64

int main(int argc, char* argv[]) {
    char* p1 = (char*)malloc(MAX_STR_SIZE * sizeof(char)); // Alocatting memory to store the string variable
    char* p2 = (char*)malloc(MAX_STR_SIZE * sizeof(char)); // Alocatting memory to store the resultant string

    strcpy(p1, argv[1]);
    strcpy(p2, argv[2]);
    
    if (strstr(p2,p1) != NULL) {
        printf("The string%s belongs to the string %s\n", p1, p2);
    }
    else {
        printf("The string%s does not belong to the string %s\n", p1, p2);
    }

    return EXIT_SUCCESS;
}