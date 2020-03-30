/*
   CSC 111 - Fall 2019 - Assignment 7

   Jason Thomo - V00949336 - 25/11/2019

    Print every word in a text file to output in a specific format
*/

#include <stdio.h>
#include <ctype.h>

int is_word_character(char c){
    if (isalpha(c) || c == '-' || c == '\'')
        return 1;
    else
        return 0;
}

int main() {

    FILE* fp = fopen("input_text.txt", "r");

    char word[100];
    char ch = fgetc(fp);
    int len=0;
    while (ch != EOF) {
        if (is_word_character(ch)) {
            word[len] = ch;
            len++;
        } else {
            word[len] = '\0';
            if (len > 0) {
                printf("Word (%d characters): ", len);
                for (int i=0; i < len; i++)
                    printf("%c", word[i]);
                printf("\n");
            }
            len=0;
        }
        ch = fgetc(fp);
    }
    if (len > 0) {
        printf("Word (%d characters): ", len);
        for (int i=0; i < len; i++)
            printf("%c", word[i]);
    }

    fclose(fp);

    return 0;
}