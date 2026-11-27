#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int gateID;
    int entries;
    int exits;
    int isOpen;
} Gate;

int main() {
    int n, maxCapacity;
    printf("Enter initial number of gates and max venue capacity: ");
    scanf("%d %d", &n, &maxCapacity);

    Gate *gates = malloc(n * sizeof(Gate));
    for(int i=0; i<n; i++) {
        gates[i].gateID = i + 1;
        gates[i].entries = 0;
        gates[i].exits = 0;
        gates[i].isOpen = 1;
    }

    int totalEntries = 0, totalExits = 0;
    int inside = totalEntries - totalExits;
    printf("People currently inside: %d\n", inside);

    free(gates);
    return 0;
}
