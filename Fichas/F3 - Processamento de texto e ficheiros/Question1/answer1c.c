#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STR_SIZE 64

int main(int argc, char* argv[]) {
    char* p1 = (char*)malloc(MAX_STR_SIZE * sizeof(char)); // Alocatting memory to store the string variable (principal string)
    char* p2 = (char*)malloc(MAX_STR_SIZE * sizeof(char)); // Alocatting memory to store the resultant string (the smallest string)
    int res = 0;

    strcpy(p1, argv[1]);
    strcpy(p2, argv[2]);
    
    for (int i = 0; i <= strlen(p1) - strlen(p2); i++) {
        int count = 0; // Size of the new strig that is being created
        int j = 0; // Index to access the smallest string (p2)
        int k = i; // Index of the principal string, but we need to increment
        while (p1[k] == p2[j]) {
            count++; // size of the string that is being analyzed
            if (count == strlen(p2)) { // If he manage to get to the last letter of the smallest string and if it's the same, then increment res
                res++;
                break;
            }
            j++;
            k++;
        }

    }

    printf("The string '%s' appears %d times in the string '%s'.\n", p2, res, p1);

    return EXIT_SUCCESS;
}