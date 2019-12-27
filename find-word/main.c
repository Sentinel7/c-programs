#include <stdio.h>
#include <string.h>

int find_word_idx(char* str, char* w) {
    int found_word = 0;
    for (int i=0; i < strlen(str); i++) {
        if (str[i] == w[0]) {

            for (int j=0; j < strlen(w); j++) {
                if (str[i+j] == '\0')
                    return -1;
                else if (str[i+j] != w[j]) {
                    found_word = 0;
                    break;
                } else
                    found_word = 1;
            }
            if (found_word)
                return i;
        }
    }
    return -1;
}

int main() {

    char* sentence = "hello my name is Jason";
    char* word = "Jason";
    int word_idx = find_word_idx(sentence, word);
    printf("Index: %d\n", word_idx);

    return 0;
}