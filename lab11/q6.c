#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int hour;
    int minute;
    float temperature;
} Reading;

int main() {
    int n;
    printf("Enter initial number of temperature readings: ");
    scanf("%d", &n);

    Reading *readings = malloc(n * sizeof(Reading));
    for(int i = 0; i < n; i++) {
        printf("Enter hour, minute, and temperature for reading %d: ", i + 1);
        scanf("%d %d %f", &readings[i].hour, &readings[i].minute, &readings[i].temperature);
    }

    float highest = readings[0].temperature, lowest = readings[0].temperature;
    float sum = 0;
    for(int i = 0; i < n; i++) {
        sum += readings[i].temperature;
        if(readings[i].temperature > highest) highest = readings[i].temperature;
        if(readings[i].temperature < lowest) lowest = readings[i].temperature;
    }

    printf("Highest Temp: %.2fC | Lowest Temp: %.2fC | Avg: %.2fC\n", highest, lowest, sum / n);

    free(readings);
    return 0;
}
