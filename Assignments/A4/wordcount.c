/* day.c
   CSC 111 - Fall 2019 - Assignment 4

   B. Bird - 09/30/2019

   Jason Thomo - V00949336 - 10/1/2019
*/

#include <stdio.h>
#include <ctype.h>

int main() {

    char c = getchar();
    int wordCount = 0;
    int lineCount = 1;
    int charCount = 0;
    int isWord = 0;

    while (c != '#') {
        charCount++;
        if (isspace(c)) {
            if (c == '\n') {
                if (isWord == 1) {
                    wordCount++;
                    isWord = 0;
                }
                lineCount++;
            } else if (isWord == 1) {
                wordCount++;
                isWord = 0;
            }
        } else {
            isWord = 1;
        }
        c = getchar();
    }
    if (isWord) wordCount++;

    printf("Characters: %d, Words: %d, Lines: %d", charCount, wordCount, lineCount);

    return 0;
}