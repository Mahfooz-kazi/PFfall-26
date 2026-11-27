#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char customerName[50];
    char carType; 
    int duration;
    char unit; 
    float totalCost;
} Rental;

int main() {
    int n;
    printf("Enter number of rentals: ");
    scanf("%d", &n);

    Rental *rentals = malloc(n * sizeof(Rental));
    float totalRevenue = 0;

    for(int i=0; i<n; i++) {
        printf("Enter customer name, car type (E/S/L), duration, unit (H/D):\n");
        scanf("%s %c %d %c", rentals[i].customerName, &rentals[i].carType, &rentals[i].duration, &rentals[i].unit);

        float rate = (rentals[i].carType == 'E') ? 500 : (rentals[i].carType == 'S' ? 1000 : 2000);
        float cost = (rentals[i].unit == 'D') ? rentals[i].duration * (rate * 24) : rentals[i].duration * rate;

        if(rentals[i].unit == 'D' && rentals[i].duration > 7) cost *= 0.90;
        else if(rentals[i].unit == 'D' && rentals[i].duration > 3) cost *= 0.95;

        cost *= 1.16; 
        rentals[i].totalCost = cost;
        totalRevenue += cost;

        printf("Invoice for %s: Total Cost = Rs. %.2f\n", rentals[i].customerName, cost);
    }

    printf("Total Revenue for the Day: Rs. %.2f\n", totalRevenue);
    free(rentals);
    return 0;
}
