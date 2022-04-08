// Answer7
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STR_SIZE 64


// Está a dar Segementation fault (Core dumped)?
int main(int argc, char* argv[]) {
    char* sent = (char*)malloc(MAX_STR_SIZE * sizeof(char));
    char* f = (char*)malloc(MAX_STR_SIZE * sizeof(char));
    //int line = 1, col = 1;
    char ch[2] = "\0\0";
    char* substr;

    strcpy(sent, argv[1]); // string with the sentence to search
    strcpy(f, argv[2]); // string with the name of the file

    FILE* file = fopen(f, "r");

    /*
    ch = fgetc(file); // Get the firt character of the file
    while (ch != EOF) {
        col++; // Increment the number of the column

        if (ch == ' ') { // character is equal to a space
            if (strcmp(word, sent)) { // If the word testing is the same as the one provided
                printf("[%d:%d]\n", line, col);
            }
            char* word; // Reset the word that will be tested
        }
        else if (ch == '\n') { // If we get to the end of the line
            if (strcmp(word, sent)) { // If the word testing is the same as the one provided
                printf("[%d:%d]\n", line, col);
            }
            line++; // Increment the number of the line
            col = 0; // Reset the number of the column
        }
        else { // If the character is a letter
            strcat(word, ch); // Add the letter to the current word
        }

        ch = fgetc(file); // Get the next character to analyze
    }
    fclose(file);
    */

   /*
    char word[] = "Ola! ";
    char ch[] = "Ol";
    char* c1;

    c1 = strcat(word, ch);
    printf("word + ch = %s\n", c1);
    */

    //while ((ch = fgetc(file)) != EOF) {
        //printf("%c", ch);

    //}

    /*
    char ch[] = "";
    char word[] = "";
    int num = 0;
    //ch1 = fgetc(file);
    while ((strcat(ch, fgetc(file))) != EOF) {
        //printf("%c", ch);
        if (ch != ' ' || ch != '\n') {
            word = strcat(word, ch);
        }
        if (ch == ' ' || ch == '\n') {
            word = strcat(word, ch);
            printf("%c", word);
        }
    }
    */

   
   ch[0] = fgetc(file);
   int line = 1; int col = 1; int col2 = 1;
   char word[99] = ""; // Word to be added the letter
    while (ch[0] != EOF) {
        if (ch[0] == '\n') { // Next line
            int pos = 0;
            while ((substr = strstr(word + pos, sent)) != NULL) { // If the word constructed (word) is the same as the word given (sent)
                printf("[%d:%d]\n", line, col + abs(substr - word));
                pos += strlen(sent);
            }
            col = 1;
            col2 = 1;
            line++;
            memset(word, 0, sizeof(word)); // Reset the word to be added the letter
        }
        else if (ch[0] != ' ' && ch[0] != '\n') { // take the next word of the file
            strncat(word, ch, 1); // Append the letter to the word
            col2++;
        }
        else { // If the character of the file is a space
            //printf("%s\n", word); printf("%s\n", sent);
            int pos = 0;
            while ((substr = strstr(word + pos, sent)) != NULL) { // If the word constructed (word) is the same as the word given (sent)
                printf("[%d:%d]\n", line, col + abs(substr - word));
                pos += strlen(sent);
            }
            col2++;
            col = col2;
            memset(word, 0, sizeof(word)); // Reset the word to be added the letter
        }
        ch[0] = fgetc(file);
    }
    fclose(file);
   

    return EXIT_SUCCESS;
}