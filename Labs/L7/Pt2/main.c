#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_characters(char str[]){
    int count = 0;
    while (str[count] != '\0')
        count++;
    return count;
}

int count_words(char str[]){
    int words = 0;
    int hasCh = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (!isspace(str[i])) {
            hasCh = 1;
        } else if (isspace(str[i]) && hasCh == 1) {
            hasCh = 0;
            words++;
        }
        i++;
    }
    if (hasCh == 1)
        words++;
    return words;
}

void capitalize(char str[]){
    int previous_space = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (isspace(str[i]))
            previous_space = 1;
        else if (!isspace(str[i]) && previous_space == 1) {
            str[i] = toupper(str[i]);
            previous_space = 0;
        }
        i++;
    }
}

void invert_capitalization(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        if (isupper(str[i]))
            str[i] = tolower(str[i]);
        else if (islower(str[i]))
            str[i] = toupper(str[i]);
        i++;
    }
}

int main(){

    char S1[] = "Raspberry";
    char S2[] = "      "; //Contains 0 words, 6 characters
    char S3[] = "CSc 111 SPRing 2019";
    char S4[] = "   raspberry pear pineapple banana";
    char S5[] = "   <-- spaces at the beginning, spaces at the end --> ";

    //Make a new array to use as temporary storage.
    char W[1000];

    printf("S1: \"%s\"\n", S1 );
    printf("Characters: %d\n", count_characters(S1) );
    printf("Words: %d\n", count_words(S1) );
    strcpy(W, S1);
    capitalize(W);
    printf("Capitalized: \"%s\"\n", W );
    strcpy(W, S1);
    invert_capitalization(W);
    printf("Inverted Capitalization: \"%s\"\n", W );
    printf("\n");

    printf("S2: \"%s\"\n", S2 );
    printf("Characters: %d\n", count_characters(S2) );
    printf("Words: %d\n", count_words(S2) );
    strcpy(W, S2);
    capitalize(W);
    printf("Capitalized: \"%s\"\n", W );
    strcpy(W, S2);
    invert_capitalization(W);
    printf("Inverted Capitalization: \"%s\"\n", W );
    printf("\n");

    printf("S3: \"%s\"\n", S3);
    printf("Characters: %d\n", count_characters(S3) );
    printf("Words: %d\n", count_words(S3) );
    strcpy(W, S3);
    capitalize(W);
    printf("Capitalized: \"%s\"\n", W );
    strcpy(W, S3);
    invert_capitalization(W);
    printf("Inverted Capitalization: \"%s\"\n", W );
    printf("\n");

    printf("S4: \"%s\"\n", S4 );
    printf("Characters: %d\n", count_characters(S4) );
    printf("Words: %d\n", count_words(S4) );
    strcpy(W, S4);
    capitalize(W);
    printf("Capitalized: \"%s\"\n", W );
    strcpy(W, S4);
    invert_capitalization(W);
    printf("Inverted Capitalization: \"%s\"\n", W );
    printf("\n");

    printf("S5: \"%s\"\n", S5 );
    printf("Characters: %d\n", count_characters(S5) );
    printf("Words: %d\n", count_words(S5) );
    strcpy(W, S5);
    capitalize(W);
    printf("Capitalized: \"%s\"\n", W );
    strcpy(W, S5);
    invert_capitalization(W);
    printf("Inverted Capitalization: \"%s\"\n", W );
    printf("\n");

    return 0;
}