#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int month, year;
} Date;

typedef struct {
    char medicineName[40];
    int quantityAvailable;
    float unitPrice;
    int reorderLevel;
    Date expiry;
} Medicine;

int main() {
    int n;
    printf("Enter number of medicines in inventory: ");
    scanf("%d", &n);

    Medicine *meds = malloc(n * sizeof(Medicine));
    float totalInventoryValue = 0;

    for(int i=0; i<n; i++) {
        printf("Enter name, quantity, unit price, reorder level, expiry (MM YYYY):\n");
        scanf("%s %d %f %d %d %d", meds[i].medicineName, &meds[i].quantityAvailable, 
              &meds[i].unitPrice, &meds[i].reorderLevel, &meds[i].expiry.month, &meds[i].expiry.year);

        totalInventoryValue += meds[i].quantityAvailable * meds[i].unitPrice;
        if(meds[i].quantityAvailable < meds[i].reorderLevel) {
            printf("LOW STOCK ALERT: %s\n", meds[i].medicineName);
        }
    }

    printf("Total Inventory Value: Rs. %.2f\n", totalInventoryValue);
    free(meds);
    return 0;
}
```[cite: 1]
