/*
   CSC 111 - Fall 2019 - Assignment 7

   Jason Thomo - V00949336 - 25/11/2019

   Print out all the unique words in a text file
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct{
    char word[100];
} WordEntry;

int is_word_character(char c){
    if (isalpha(c) || c == '-' || c == '\'')
        return 1;
    else
        return 0;
}

int lookup(WordEntry entries[], char word[], int numW) {
    for (int w=0; w < numW; w++) {
        if (strcmp(word, entries[w].word) == 0)
            return w;
    }
    return -1;
}

int main() {

    FILE* fp = fopen("input_text.txt", "r");

    WordEntry entries[10000];
    char word[100];
    int numEntries = 0;
    int len = 0;
    char ch;

    do {
        ch = fgetc(fp);
        if (is_word_character(ch)) { // inside word
            word[len] = tolower(ch);
            len++;
        } else { // end of word
            if (len == 0)
                continue;

            word[len] = '\0';

            int w = lookup(entries, word, numEntries);
            if (w == -1) {
                strcpy(entries[numEntries].word, word);
                printf("%s\n", word);
                numEntries++;
            }
            len=0;
        }
    } while (ch != EOF);

    fclose(fp);

    return 0;
}