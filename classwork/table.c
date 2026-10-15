#include <stdio.h>

int main()
{
    int t, j, i;

    printf("Enter number of tables: ");
    scanf("%d", &t);

    for (j = 1; j <= t; j++) {
        printf("%d: ", j);

        for (i = 1; i <= 10; i++) {
            printf("%d\t", j * i);
        }

        printf("\n");
    }

    return 0;
}
