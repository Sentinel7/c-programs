#include <stdio.h>

int merge(int arr1[], int arr2[], int arr1Size, int arr2Size) {

    int i1 = 0;
    int i2 = 0;
    int matches = 0;
    while (1) {
        if (arr1[i1] == arr2[i2]) {
            matches++;
            i1++;
            i2++;
        } else {
            if (arr1[i1] < arr2[i2])
                i1++;
            else
                i2++;
        }
        if (i1 == arr1Size || i2 == arr2Size)
            break;
    }
    return matches;
}

int main() {

    int N, M;
    scanf("%d", &N);
    scanf("%d", &M);

    while (N != 0 && M != 0) {
        int jack[N];
        int jill[M];
        int numMatching = 0;
        for (int i=0; i < N; i++) {
            scanf("%d", &jack[i]);
        }
        for (int i=0; i < M; i++) {
            scanf("%d", &jill[i]);
        }
        printf("%d\n", merge(jack, jill, N, M));

        scanf("%d", &N);
        scanf("%d", &M);
    }

    return 0;
}