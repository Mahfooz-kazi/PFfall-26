#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int day, month, year;
} Date;

typedef struct {
    char bookTitle[60];
    char memberID[10];
    Date checkoutTime;
    int returnDueDays;
    Date dueDate;
} Checkout;

void calculateDueDate(Checkout *c) {
    c->dueDate = c->checkoutTime;
    c->dueDate.day += c->returnDueDays;
}

int main() {
    Checkout *checkouts = malloc(sizeof(Checkout));
    printf("Enter Book Title, Member ID, Checkout Date (D M Y), and Return Due Days:\n");
    scanf("%s %s %d %d %d %d", checkouts[0].bookTitle, checkouts[0].memberID, 
          &checkouts[0].checkoutTime.day, &checkouts[0].checkoutTime.month, 
          &checkouts[0].checkoutTime.year, &checkouts[0].returnDueDays);

    calculateDueDate(&checkouts[0]);
    printf("Due Date: %d/%d/%d\n", checkouts[0].dueDate.day, checkouts[0].dueDate.month, checkouts[0].dueDate.year);

    free(checkouts);
    return 0;
}
