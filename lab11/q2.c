#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Address {
    char street[40];
    char city[30];
    char postalCode[10];
};

struct TimeStamp {
    int hour;
    int minute;
    int second;
};

struct PizzaOrder {
    int orderID;
    char customerName[30];
    struct Address address;
    struct TimeStamp orderTime;
    struct TimeStamp deliveryTime;
    char pizzaSize;
    float price;
};

void swapOrders(struct PizzaOrder *a, struct PizzaOrder *b) {
    struct PizzaOrder temp = *a;
    *a = *b;
    *b = temp;
}

void printComparison(struct PizzaOrder *a, struct PizzaOrder *b) {
    printf("%-20s | %-20s\n", "Order 1", "Order 2");
    printf("----------------------------------------\n");
    printf("ID: %-16d | ID: %-16d\n", a->orderID, b->orderID);
    printf("Name: %-14s | Name: %-14s\n", a->customerName, b->customerName);
    printf("City: %-14s | City: %-14s\n", a->address.city, b->address.city);
    printf("Price: Rs.%.2f        | Price: Rs.%.2f\n", a->price, b->price);
}

int main() {
    struct PizzaOrder o1, o2;

    printf("Enter Order 1 (ID, Name, Street, City, PostalCode, HH, MM, SS, Size, Price):\n");
    scanf("%d %s %s %s %s %d %d %d %c %f", &o1.orderID, o1.customerName, o1.address.street, o1.address.city, o1.address.postalCode, &o1.orderTime.hour, &o1.orderTime.minute, &o1.orderTime.second, &o1.pizzaSize, &o1.price);

    printf("Enter Order 2 (ID, Name, Street, City, PostalCode, HH, MM, SS, Size, Price):\n");
    scanf("%d %s %s %s %s %d %d %d %c %f", &o2.orderID, o2.customerName, o2.address.street, o2.address.city, o2.address.postalCode, &o2.orderTime.hour, &o2.orderTime.minute, &o2.orderTime.second, &o2.pizzaSize, &o2.price);

    int cmp = strcmp(o1.address.city, o2.address.city);
    if (cmp < 0) printf("%s comes first alphabetically.\n", o1.address.city);
    else if (cmp > 0) printf("%s comes first alphabetically.\n", o2.address.city);
    else printf("Both cities are identical.\n");

    for(int i=0; o1.address.postalCode[i] != '\0'; i++)
        if(!isdigit(o1.address.postalCode[i])) printf("Invalid postal code in Order 1\n");
    for(int i=0; o2.address.postalCode[i] != '\0'; i++)
        if(!isdigit(o2.address.postalCode[i])) printf("Invalid postal code in Order 2\n");

    int sec1 = o1.orderTime.hour * 3600 + o1.orderTime.minute * 60 + o1.orderTime.second;
    int sec2 = o2.orderTime.hour * 3600 + o2.orderTime.minute * 60 + o2.orderTime.second;
    if (sec1 < sec2) printf("Order 1 was placed earlier.\n");
    else printf("Order 2 was placed earlier.\n");

    printf("Before swap - Name 1: %s, Name 2: %s\n", o1.customerName, o2.customerName);
    swapOrders(&o1, &o2);
    printf("After swap - Name 1: %s, Name 2: %s\n", o1.customerName, o2.customerName);

    int addMins;
    do {
        printf("Enter minutes to add (1-120): ");
        scanf("%d", &addMins);
    } while(addMins < 1 || addMins > 120);

    o1.deliveryTime = o1.orderTime;
    o1.deliveryTime.minute += addMins;
    if (o1.deliveryTime.minute >= 60) {
        o1.deliveryTime.hour += o1.deliveryTime.minute / 60;
        o1.deliveryTime.minute %= 60;
    }
    if (o1.deliveryTime.hour >= 24) {
        o1.deliveryTime.hour %= 24;
        printf("Next day delivery for Order 1!\n");
    }

    printComparison(&o1, &o2);
    float diff = o1.price > o2.price ? o1.price - o2.price : o2.price - o1.price;
    printf("Price difference: Rs. %.2f\n", diff);

    return 0;
}
