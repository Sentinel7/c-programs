#include <stdio.h>
#include <stdlib.h>

int isValid(int I[], int J[], int length) {

    for (int i=0; i < length-1; i++) {
        for (int j=i+1; j < length; j++) {
            if (I[i] == I[j])
                return 0;
            if (J[i] == J[j])
                return 0;
            if (abs(I[i] - I[j]) == abs(J[i] - J[j]))
                return 0;
        }
    }
    return 1;
}

int main() {

    int N = 8;
    int I[N];
    int J[N];
    for (int i=0; i < N; i++) {
        I[i] = i;

        char c = getchar();
        int foundQueen = 0;
        int j = 0;
        while (c != '\n') {
            if (c == '*') {
                J[i] = j;
                foundQueen = 1;
            }
            j++;
            c = getchar();
        }
        if (foundQueen == 0) {
            printf("invalid");
            return 0;
        }
    }

    if (isValid(I, J, N))
        printf("valid");
    else printf("invalid");

    return 0;
}