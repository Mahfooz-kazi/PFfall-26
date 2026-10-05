#include <stdio.h>

int main()
{
    int transfers[10] = {5000, 50, 12000, 500000, 20,
                         8000, 25000, 300, 450000, 15000};

    int i;
    int flagged = 0;
    int normalCount = 0;
    int normalSum = 0;
    int largest = transfers[0];

    for (i = 0; i < 10; i++)
    {
        // Flag too small transfers
        if (transfers[i] < 100)
        {
            printf("Transfer %d = %d: Too Small\n", i + 1, transfers[i]);
            flagged++;
        }

        // Flag too large transfers
        else if (transfers[i] > 200000)
        {
            printf("Transfer %d = %d: Too Large\n", i + 1, transfers[i]);
            flagged++;
        }

        // Normal transfers
        else
        {
            normalSum = normalSum + transfers[i];
            normalCount++;
        }

        // Find largest transfer
        if (transfers[i] > largest)
        {
            largest = transfers[i];
        }
    }

    printf("\nTotal flagged transfers = %d\n", flagged);

    printf("Average of normal transfers = %.2f\n",
           (float)normalSum / normalCount);

    printf("Largest transfer = %d\n", largest);

    return 0;
}