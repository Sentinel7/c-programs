#include <stdio.h>
#include <ctype.h>

int main() {

    FILE* fp = fopen("some_file.txt", "r");

    int numChars=0;
    int numAlpha=0;
    int lines = 0;
    char buffer[100];
    while (fgets(buffer, 100, fp) != NULL) {
        int i=0;
        while (buffer[i] != '\0') {
            printf("%c", toupper(buffer[i]));
            if (isalpha(buffer[i]))
                numAlpha++;
            i++;
        }
        numChars += i;
        lines++;
    }
    printf("\nTotal Characters: %d, Total alphabetical characters: %d, Total lines: %d", numChars, numAlpha, lines);

    fclose(fp);

    return 0;
}