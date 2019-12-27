#include <stdio.h>
#include <string.h>

void flip(char* str, int i, int j) {
    char tmp = str[i];
    str[i] = str[j];
    str[j] = tmp;
}

void str_reverse(char* str) {
    int n = strlen(str);
    for (int i=0, j = n-1; i < n/2; i++, j--) {
        flip(str, i, j);
    }
}

int main() {

    char s1[] = "Hello World";
    str_reverse(s1);
    printf("%s", s1);

    return 0;
}