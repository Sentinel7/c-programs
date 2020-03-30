/*
   CSC 111 - Fall 2019 - Assignment 7

   Jason Thomo - V00949336 - 25/11/2019

   Analyze text file and print out the total words, # of unique words, longest/shortest words, and most frequent words.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct{
    char word[100];
    int num_occurrences;
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

void print_total(WordEntry entries[], int numEntries) {
    int total = 0;
    for (int i=0; i < numEntries; i++) {
        total += entries[i].num_occurrences;
    }
    printf("Total words: %d\n", total);
}

void print_unique(WordEntry entries[], int numEntries) {
    printf("Unique words: %d\n", numEntries);
}

void print_longest(WordEntry entries[], int numEntries) {
    int longest_len = strlen(entries[0].word);
    for (int i=1; i < numEntries; i++) {
        if (strlen(entries[i].word) > longest_len)
            longest_len = strlen(entries[i].word);
    }
    printf("Longest words:\n");
    for (int i=0; i < numEntries; i++) {
        if (strlen(entries[i].word) == longest_len)
            printf("  %s\n", entries[i].word);
    }
    printf("\n");
}

void print_shortest(WordEntry entries[], int numEntries) {
    int shortest_len = strlen(entries[0].word);
    for (int i=1; i < numEntries; i++) {
        if (strlen(entries[i].word) < shortest_len)
            shortest_len = strlen(entries[i].word);
    }
    printf("Shortest words:\n");
    for (int i=0; i < numEntries; i++) {
        if (strlen(entries[i].word) == shortest_len)
            printf("  %s\n", entries[i].word);
    }
    printf("\n");
}

void print_frequent(WordEntry entries[], int numEntries) {
    int most_occurences = entries[0].num_occurrences;
    for (int i=1; i < numEntries; i++) {
        if (entries[i].num_occurrences > most_occurences)
            most_occurences = entries[i].num_occurrences;
    }
    printf("Most frequently occurring words:\n");
    for (int i=0; i < numEntries; i++) {
        if (entries[i].num_occurrences == most_occurences)
            printf("  %s\n", entries[i].word);
    }
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
            if (w != -1) {
                entries[w].num_occurrences++;
            } else {
                strcpy(entries[numEntries].word, word);
                entries[numEntries].num_occurrences = 1;
                numEntries++;
            }
            len=0;
        }
    } while (ch != EOF);

    print_total(entries, numEntries);
    print_unique(entries, numEntries);
    print_longest(entries, numEntries);
    print_shortest(entries, numEntries);
    print_frequent(entries, numEntries);

    fclose(fp);

    return 0;
}