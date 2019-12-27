#include <stdio.h>
#include <stdbool.h>

bool find(int el, int arr[], int arrSize) {
    bool found = false;
    for (int i=0; i < arrSize; i++) {
        if (arr[i] == el)
            found = true;
    }
    return found;
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
            if (find(jill[i], jack, N))
                numMatching++;
        }
        printf("%d\n", numMatching);

        scanf("%d", &N);
        scanf("%d", &M);
    }

    return 0;
}