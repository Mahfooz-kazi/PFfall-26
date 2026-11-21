#include <stdio.h>

void grow(int heights[], int n) {
    if (n == 0) return;
    grow(heights, n - 1);
    heights[n - 1] += (int)(heights[n - 1] * 0.10);
}

int tallest(int heights[], int n) {
    if (n == 1) return 0;
    int prevMax = tallest(heights, n - 1);
    return (heights[n - 1] > heights[prevMax]) ? (n - 1) : prevMax;
}

int search(int heights[], int n, int target) {
    if (n == 0) return -1;
    if (heights[n - 1] == target) return n - 1;
    return search(heights, n - 1, target);
}

int main() {
    int ids[6] = {101, 102, 103, 104, 105, 106};
    int heights[6] = {45, 120, 78, 200, 95, 150};

    grow(heights, 6);
    printf("New heights: ");
    for (int i = 0; i < 6; i++) printf("%d ", heights[i]);
    printf("\n");

    int tIdx = tallest(heights, 6);
    printf("Tallest: tower %d (%d m)\n", ids[tIdx], heights[tIdx]);

    int target;
    printf("Height to search: ");
    scanf("%d", &target);
    int sIdx = search(heights, 6, target);
    if (sIdx != -1) printf("Tower %d is %d m\n", ids[sIdx], target);
    else printf("Tower not found\n");

    return 0;
}
