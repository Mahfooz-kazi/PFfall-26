#include <stdio.h>

#define N 12

int main() {
    int cars[N];
    int sum = 0;

    printf("Enter cars waiting at %d signals:\n", N);

    /* Loop 1: read input and calculate the average */
    for (int i = 0; i < N; i++) {
        printf("Signal %d: ", i + 1);
        scanf("%d", &cars[i]);
        sum += cars[i];
    }
    double average = (double)sum / N;

    /* Loop 2: compare each signal to the average, track highest/lowest */
    int overloaded = 0;
    int maxIdx = 0, minIdx = 0;

    for (int i = 0; i < N; i++) {
        if (cars[i] > average) {
            overloaded++;
        }
        if (cars[i] > cars[maxIdx]) maxIdx = i;
        if (cars[i] < cars[minIdx]) minIdx = i;
    }

    printf("\nAverage cars waiting : %.2f\n", average);
    printf("Overloaded signals   : %d\n", overloaded);
    printf("Highest              : Signal %d (%d cars)\n", maxIdx + 1, cars[maxIdx]);
    printf("Lowest               : Signal %d (%d cars)\n", minIdx + 1, cars[minIdx]);
    printf("Difference           : %d\n", cars[maxIdx] - cars[minIdx]);

    return 0;
}
