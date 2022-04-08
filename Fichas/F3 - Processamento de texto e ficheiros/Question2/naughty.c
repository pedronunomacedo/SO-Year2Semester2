// Answer 2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int f(char* content) {
    char str[8];
    int result = 2;
    (void)strcpy(str, content);
    return result;
}

int main(int argc, char* argv[]) {
    if (argc == 2)
        printf("result = %d\n", f(argv[1]));
    return EXIT_SUCCESS;
}