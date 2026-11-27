#include <stdio.h>
#include <string.h>

typedef struct {
    char customerName[30];
    int cardNumber;
    int cupsBought;
    float totalSpent;
} LoyaltyCard;

void printCard(LoyaltyCard c) {
    printf("============================\n");
    printf("BREW HAVEN LOYALTY CARD\n");
    printf("============================\n");
    printf("Name : %s\n", c.customerName);
    printf("Card # : %d\n", c.cardNumber);
    printf("Cups : %d\n", c.cupsBought);
    printf("Spent : Rs. %.2f\n", c.totalSpent);
    printf("============================\n");
}

void addCups(LoyaltyCard *c, int cups, float pricePerCup) {
    c->cupsBought += cups;
    c->totalSpent += cups * pricePerCup;
}

int main() {
    LoyaltyCard card1, card2;

    printf("Enter details for Card 1 (Name, Card#, Cups, Total Spent):\n");
    scanf("%s %d %d %f", card1.customerName, &card1.cardNumber, &card1.cupsBought, &card1.totalSpent);

    printf("Enter details for Card 2 (Name, Card#, Cups, Total Spent):\n");
    scanf("%s %d %d %f", card2.customerName, &card2.cardNumber, &card2.cupsBought, &card2.totalSpent);

    if (card1.cupsBought > card2.cupsBought)
        printf("%s has bought more cups.\n", card1.customerName);
    else if (card2.cupsBought > card1.cupsBought)
        printf("%s has bought more cups.\n", card2.customerName);
    else
        printf("Both customers have bought the same number of cups.\n");

    printCard(card1);
    printCard(card2);

    float avg1 = card1.cupsBought > 0 ? card1.totalSpent / card1.cupsBought : 0;
    float avg2 = card2.cupsBought > 0 ? card2.totalSpent / card2.cupsBought : 0;
    printf("Average spent per cup for %s: Rs. %.2f\n", card1.customerName, avg1);
    printf("Average spent per cup for %s: Rs. %.2f\n", card2.customerName, avg2);

    int tiers[2] = {card1.cupsBought, card2.cupsBought};
    char *names[2] = {card1.customerName, card2.customerName};
    for (int i = 0; i < 2; i++) {
        printf("Tier for %s: ", names[i]);
        switch (tiers[i] / 10) {
            case 0:
                if (tiers[i] < 10) printf("Bronze\n");
                else printf("Silver\n");
                break;
            case 1:
            case 2:
                if (tiers[i] < 25) printf("Silver\n");
                else printf("Gold\n");
                break;
            case 3:
            case 4:
                printf("Gold\n");
                break;
            default:
                printf("Platinum\n");
                break;
        }
    }

    addCups(&card1, 5, 250.0);
    addCups(&card2, 12, 250.0);

    int bonus1 = card1.cupsBought / 10;
    card1.cupsBought += bonus1;
    int bonus2 = card2.cupsBought / 10;
    card2.cupsBought += bonus2;

    printf("\nAfter Bonus Update:\n");
    printCard(card1);
    printCard(card2);

    return 0;
}
