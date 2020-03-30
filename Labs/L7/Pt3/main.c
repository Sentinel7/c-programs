#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* condense_spaces(str, output)
   Given a string str, copy the contents into
   the string output, deleting any runs of consecutive
   spaces. For example, multiple spaces between words
   should be condensed into a single space.
   Multiple spaces at the beginning and end of the string
   should also be condensed into a single space.
   Use the isspace() function to detect whether a character
   is a space.
*/
void condense_spaces(char str[], char output[]) {
    int hasPrevSpace = 0;
    int i=0;
    int j=0;
    while (str[i] != '\0') {
        if (!isspace(str[i])) {
            output[j] = str[i];
            hasPrevSpace = 0;
            i++;
            j++;
        } else if (isspace(str[i]) && !hasPrevSpace) {
            output[j] = str[i];
            hasPrevSpace = 1;
            i++;
            j++;
        } else if (isspace(str[i]) && hasPrevSpace) {
            i++;
        }
    }
    output[j] = '\0';
}

/* remove_leading_spaces(str, output)
   Given a string str, copy the contents into
   the string output, ignoring any leading
   spaces (spaces at the beginning of the string).
*/
void remove_leading_spaces(char str[], char output[]) {
    int found_ch = 0;
    int i=0;
    int j=0;
    while (str[i] != '\0') {
        if (!isspace(str[i])) {
            output[j] = str[i];
            found_ch = 1;
            i++;
            j++;
        } else if (isspace(str[i]) && found_ch) {
            output[j] = str[i];
            i++;
            j++;
        } else if (isspace(str[i]) && !found_ch) {
            i++;
        }
    }
    output[j] = '\0';
}

/* remove_trailing_spaces(str, output)
   Given a string str, copy the contents into
   the string output, ignoring any trailing
   spaces (spaces at the end of the string).
*/
void remove_trailing_spaces(char str[], char output[]) {
    int len = strlen(str);
    int foundCh = 0;
    int i = len-1;
    while (i >= 0) {
        if (!isspace(str[i]) && !foundCh) {
            output[i+1] = '\0';
            output[i] = str[i];
            foundCh = 1;
            i--;
        } else if (foundCh) {
            output[i] = str[i];
            i--;
        } else {
            i--;
        }
    }
}

int main(){

    char S1[] = "Hello         World ";
    char S2[] = "      "; //Contains 0 words, 6 characters
    char S3[] = "CSC    111    Spring 2019";
    char S4[] = "   raspberry    pear pineapple    banana  ";
    char S5[] = "   <-- spaces at the beginning, spaces at the end --> ";

    //Make a new array for the output
    char W[1000];

    printf("S1: \"%s\"\n", S1);
    condense_spaces(S1, W);
    printf("With spaces condensed: \"%s\"\n", W);
    remove_leading_spaces(S1, W);
    printf("With leading spaces removed: \"%s\"\n", W);
    remove_trailing_spaces(S1, W);
    printf("With trailing spaces removed: \"%s\"\n", W);
    printf("\n");

    printf("S2: \"%s\"\n", S2);
    condense_spaces(S2, W);
    printf("With spaces condensed: \"%s\"\n", W);
    remove_leading_spaces(S2, W);
    printf("With leading spaces removed: \"%s\"\n", W);
    remove_trailing_spaces(S2, W);
    printf("With trailing spaces removed: \"%s\"\n", W);
    printf("\n");

    printf("S3: \"%s\"\n", S3);
    condense_spaces(S3, W);
    printf("With spaces condensed: \"%s\"\n", W);
    remove_leading_spaces(S3, W);
    printf("With leading spaces removed: \"%s\"\n", W);
    remove_trailing_spaces(S3, W);
    printf("With trailing spaces removed: \"%s\"\n", W);
    printf("\n");

    printf("S4: \"%s\"\n", S4);
    condense_spaces(S4, W);
    printf("With spaces condensed: \"%s\"\n", W);
    remove_leading_spaces(S4, W);
    printf("With leading spaces removed: \"%s\"\n", W);
    remove_trailing_spaces(S4, W);
    printf("With trailing spaces removed: \"%s\"\n", W);
    printf("\n");

    printf("S5: \"%s\"\n", S5);
    condense_spaces(S5, W);
    printf("With spaces condensed: \"%s\"\n", W);
    remove_leading_spaces(S5, W);
    printf("With leading spaces removed: \"%s\"\n", W);
    remove_trailing_spaces(S5, W);
    printf("With trailing spaces removed: \"%s\"\n", W);
    printf("\n");

    return 0;
}