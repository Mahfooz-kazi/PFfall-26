#include <stdio.h>

int main()
{
    int size;

    printf("Enter size (1-Small, 2-Medium, 3-Large): ");
    scanf("%d", &size);

    if (size == 1)
    {
        printf("Small size selected.");
    }
    else if (size == 2)
    {
        printf("Medium size selected.");
    }
    else if (size == 3)
    {
        printf("Large size selected.");
    }
    else
    {
        printf("Invalid size.");
    }

    return 0;
}