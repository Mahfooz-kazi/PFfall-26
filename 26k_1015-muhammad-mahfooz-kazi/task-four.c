#include <stdio.h>

int main()
{
    int card, pin;
    int balance, withdrawal;
    int remaining;
    int notes2000, notes500, notes100;

    printf("Enter card status (1=Valid, 0=Blocked): ");
    scanf("%d", &card);

    printf("Enter PIN correctness (1=Correct, 0=Wrong): ");
    scanf("%d", &pin);

    printf("Enter account balance: ");
    scanf("%d", &balance);

    printf("Enter withdrawal amount: ");
    scanf("%d", &withdrawal);

    if (card == 0)
    {
        printf("Card blocked. Contact bank.\n");
    }
    else if (pin == 0)
    {
        printf("Incorrect PIN.\n");
    }
    else if (withdrawal <= 0)
    {
        printf("Invalid amount.\n");
    }
    else if (withdrawal > balance)
    {
        printf("Insufficient balance.\n");
    }
    else if (withdrawal > 25000)
    {
        printf("Daily limit exceeded.\n");
    }
    else if ((balance - withdrawal) < 1000)
    {
        printf("Minimum balance must be maintained.\n");
    }
    else
    {
        balance = balance - withdrawal;

        remaining = withdrawal;

        notes2000 = remaining / 2000;
        remaining = remaining % 2000;

        notes500 = remaining / 500;
        remaining = remaining % 500;

        notes100 = remaining / 100;

        printf("New balance: %d\n", balance);
        printf("2000 notes: %d\n", notes2000);
        printf("500 notes: %d\n", notes500);
        printf("100 notes: %d\n", notes100);
        printf("Please collect your cash.\n");
    }

    return 0;
}