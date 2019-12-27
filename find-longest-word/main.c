#include <stdio.h>
#include <string.h>
#include <ctype.h>

int get_len(char* str, int start_idx) {
    int i = 0;
    while (!isspace(str[start_idx+i]) && str[start_idx+i] != '\0') {
        i++;
    }
    return i;
}

void print_longest_word(char* str)  {
    int n = strlen(str);
    int in_word = 0;
    int longest_len = 0;
    int start_idx = -1;
    for (int i=0; i < n; i++) {
        if (!isspace(str[i]) && !in_word) {
            in_word = 1;
            int len_word = get_len(str, i);
            if (len_word > longest_len) {
                longest_len = len_word;
                start_idx = i;
            }
        } else if (isspace(str[i]) && in_word)
            in_word = 0;
    }

    for (int i=0; i < longest_len; i++) {
        printf("%c", str[start_idx+i]);
    }
}

int longest_word_length(char* str)  {
    int n = strlen(str);
    int in_word = 0;
    int longest_len = 0;
    for (int i=0; i < n; i++) {
        if (!isspace(str[i]) && !in_word) {
            in_word = 1;
            int len_word = 0;
            while (!isspace(str[i+len_word]) && str[i+len_word] != '\0')
                len_word++;
            if (len_word > longest_len)
                longest_len = len_word;
        } else if (isspace(str[i]) && in_word)
            in_word = 0;
    }
    return longest_len;
}

int main() {

    char s1[] = "aaa bbbbbbbb eeeeeeeeeeee aaaaaaa jjjjjjjjjjjjjjjjjjjjjjj";
    print_longest_word(s1);
    printf("\n%d", longest_word_length(s1));

    return 0;
}