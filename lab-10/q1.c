#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[20];
    float price;
    int stock;
} Item;

int main() {
    FILE *fp = fopen("items.txt", "w");
    if (!fp) return 1;

    Item initial_items[5] = {
        {1, "Rice", 250.00, 40},
        {2, "Sugar", 160.00, 25},
        {3, "Milk", 220.00, 30},
        {4, "CookingOil", 560.00, 12},
        {5, "Tea", 450.00, 18}
    };

    for (int i = 0; i < 5; i++) {
        fprintf(fp, "%-4d %-20s %9.2f %5d\n", initial_items[i].id, initial_items[i].name, initial_items[i].price, initial_items[i].stock);
    }
    fclose(fp);

    fp = fopen("items.txt", "rb+");
    if (!fp) return 1;

    int itemNo, qty;
    float totalBill = 0.0;

    while (1) {
        printf("Item no: ");
        scanf("%d", &itemNo);
        if (itemNo == 0) break;
        printf("Quantity: ");
        scanf("%d", &qty);

        fseek(fp, (itemNo - 1) * 42, SEEK_SET);
        Item cur;
        fscanf(fp, "%d %s %f %d", &cur.id, cur.name, &cur.price, &cur.stock);

        if (cur.stock >= qty) {
            printf("%s %d x %.2f = %.2f\n", cur.name, qty, cur.price, qty * cur.price);
            totalBill += qty * cur.price;
            cur.stock -= qty;

            fseek(fp, (itemNo - 1) * 42, SEEK_SET);
            fprintf(fp, "%-4d %-20s %9.2f %5d\n", cur.id, cur.name, cur.price, cur.stock);
            fseek(fp, 0, SEEK_CUR); 
        } else {
            printf("Only %d %s in stock\n", cur.stock, cur.name);
        }
    }

    printf("Total bill: %.2f\n", totalBill);
    fclose(fp);
    return 0;
}
