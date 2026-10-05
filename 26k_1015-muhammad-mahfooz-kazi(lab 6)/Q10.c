#include <stdio.h>

int main()
{
    int amount;
    int transactions = 0;
    int total = 0;

    while (1)
    {
        printf("Enter withdrawal amount (0 to exit): ");
        scanf("%d", &amount);

        if (amount == 0)
        {
            break;
        }

        total = total + amount;
        transactions++;

        printf("Withdrawal processed: %d\n", amount);
    }

    printf("\nATM Session Summary\n");
    printf("Total transactions: %d\n", transactions);
    printf("Total amount withdrawn: %d\n", total);

    return 0;
}