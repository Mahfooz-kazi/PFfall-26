#include <stdio.h>

typedef struct {
    char category[12];
    float amount;
} Expense;

int main() {
    FILE *fp = fopen("expenses.txt", "w");
    if (!fp) return 1;

    Expense initial[4] = {
        {"Food", 1200.00},
        {"Transport", 500.00},
        {"Books", 850.00},
        {"Mobile", 300.00}
    };
    for (int i = 0; i < 4; i++) {
        fprintf(fp, "%-12s %9.2f\n", initial[i].category, initial[i].amount);
    }
    fclose(fp);

    // Append new expense
    char cat[12];
    float amt;
    printf("Category: ");
    scanf("%s", cat);
    printf("Amount: ");
    scanf("%f", &amt);

    fp = fopen("expenses.txt", "ab");
    fprintf(fp, "%-12s %9.2f\n", cat, amt);
    fclose(fp);

    // Read latest two & fix
    fp = fopen("expenses.txt", "rb+");
    fseek(fp, -2 * 23, SEEK_END);
    Expense e1, e2;
    fscanf(fp, "%s %f", e1.category, &e1.amount);
    fscanf(fp, "%s %f", e2.category, &e2.amount);
    printf("Latest two: %s %.2f, %s %.2f\n", e1.category, e1.amount, e2.category, e2.amount);

    int entryToFix;
    float newAmt;
    printf("Entry to fix: ");
    scanf("%d", &entryToFix);
    printf("Correct amount: ");
    scanf("%f", &newAmt);

    fseek(fp, (entryToFix - 1) * 23, SEEK_SET);
    fscanf(fp, "%s %f", e1.category, &e1.amount);
    e1.amount = newAmt;

    fseek(fp, (entryToFix - 1) * 23, SEEK_SET);
    fprintf(fp, "%-12s %9.2f\n", e1.category, e1.amount);
    fseek(fp, 0, SEEK_CUR);

    rewind(fp);
    float total = 0;
    Expense temp;
    while (fscanf(fp, "%s %f", temp.category, &temp.amount) == 2) {
        printf("%s %.2f\n", temp.category, temp.amount);
        total += temp.amount;
    }
    printf("Total: %.2f\n", total);
    fclose(fp);
    return 0;
}
