#include <stdio.h>
#include <ctype.h>

int main() {

    FILE* fp = fopen("some_text.txt", "r");

    int numAlpha = 0;
    char ch = fgetc(fp);

    int c = 0;
    while (ch != EOF) {
        printf("%c", toupper(ch));
        if (isalpha(ch))
            numAlpha++;
        ch = fgetc(fp);
        c++;
    }
    printf("\nTotal Characters: %d, Total alphabetical characters: %d", c, numAlpha);

    fclose(fp);

    return 0;
}