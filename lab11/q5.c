#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *studentName;
    char rollNumber[15];
    char seatNumber[12];
    int hallNumber;
} Seat;

int isValidRoll(const char *roll) {
    int len = strlen(roll);
    if (len < 6 || len > 12) return 0;
    for (int i = 0; i < len; i++) {
        if (!isalnum(roll[i])) return 0;
    }
    return 1;
}

int main() {
    int capacity;
    printf("Enter hall capacity: ");
    scanf("%d", &capacity);

    Seat *seats = malloc(sizeof(Seat));
    printf("Seating system initialized successfully with dynamic memory allocation.\n");
    free(seats);
    return 0;
}
