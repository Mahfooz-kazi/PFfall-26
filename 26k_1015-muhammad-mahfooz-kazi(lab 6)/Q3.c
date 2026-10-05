#include <stdio.h>

int main()
{
    int stock[10];
    int minimum[10];
    int i;

    int totalOrder = 0;
    int largestOrder = 0;
    int largestIndex = -1;
    int count = 0;

    for (i = 0; i < 10; i++)
    {
        printf("Product %d - enter stock: ", i + 1);
        scanf("%d", &stock[i]);
        printf("Product %d - enter minimum: ", i + 1);
        scanf("%d", &minimum[i]);
    }

    printf("\n--- Products to reorder ---\n");

    for (i = 0; i < 10; i++)
    {
        if (stock[i] < minimum[i])
        {
            int order = minimum[i] - stock[i];

            printf("Product %d: stock = %d, minimum = %d, order = %d\n",
                   i + 1, stock[i], minimum[i], order);

            totalOrder += order;
            count++;

            if (order > largestOrder)
            {
                largestOrder = order;
                largestIndex = i;
            }
        }
    }

    if (count == 0)
    {
        printf("No products need reordering.\n");
    }
    else
    {
        printf("\nProducts needing reorder: %d\n", count);
        printf("Largest reorder: Product %d (%d units)\n", largestIndex + 1, largestOrder);
        printf("Total reorder quantity: %d\n", totalOrder);
    }

    return 0;
}