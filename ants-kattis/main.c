#include <stdio.h>

int max(int len, int arr[]) {
    int max = 0;
    for (int i=0; i < len; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int main() {

    int numCases;
    scanf("%d", &numCases);

    int earliest[numCases];
    int latest[numCases];

    for (int i=0; i < numCases; i++) {
        int beam_len;
        int n;
        scanf("%d", &beam_len);
        scanf("%d", &n);

        int ants[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &ants[i]);
        }

        int worst[n];
        int best[n];
        for (int i = 0; i < n; i++) {
            if ((beam_len - ants[i]) <= ants[i]) {
                worst[i] = ants[i];
                best[i] = beam_len - ants[i];
            } else {
                worst[i] = beam_len - ants[i];
                best[i] = ants[i];
            }
        }

        earliest[i] = max(n, best);
        latest[i] = max(n, worst);
    }

    for (int i=0; i < numCases; i++) {
        if (i == numCases-1)
            printf("%d %d", earliest[i], latest[i]);
        else
            printf("%d %d\n", earliest[i], latest[i]);
    }

    return 0;
}