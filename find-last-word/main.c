#include <stdio.h>
#include <ctype.h>
#include <string.h>

void last_word(char input_string[], char output_array[]) {
    int last_idx = 0;
    int first_idx = 0;
    int in_last_word = 0;
    int input_len = strlen(input_string);
    for (int i = input_len-1; i >= 0; i--) {
        if (!isspace(input_string[i]) && !in_last_word) {
            last_idx = i;
            in_last_word = 1;
        } else if (isspace(input_string[i]) && in_last_word) {
            first_idx = i+1;
            break;
        }
    }

    int current = first_idx;
    int len_word = (last_idx-first_idx)+1;
    int i;
    for (i=0; i < len_word; i++)
        output_array[i] = input_string[current++];
    output_array[i] = '\0';
}

int main(){
    char S1[] = "Hello World";
    char S2[] = " Raspberry";
    char S3[] = "Programming  ";
    char S4[] = " This string starts and ends with spaces ";

    char output[100];
    last_word(S1, output);
    printf("Result for S1: \"%s\"\n", output );
    last_word(S2, output);
    printf("Result for S2: \"%s\"\n", output );
    last_word(S3, output);
    printf("Result for S3: \"%s\"\n", output );
    last_word(S4, output);
    printf("Result for S4: \"%s\"\n", output );
    return 0;
}