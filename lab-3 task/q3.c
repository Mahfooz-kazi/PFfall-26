#include <stdio.h>

int main() {
    float kilometers, meters, centimeters;

    printf("Enter distance in kilometers: ");
    scanf("%f", &kilometers);

    meters = kilometers * 1000;
    centimeters = meters * 100;

    printf("Distance in Meters: %.2f meters\n", meters);
    printf("Distance in Centimeters: %.2f centimeters\n", centimeters);

    return 0;
}
