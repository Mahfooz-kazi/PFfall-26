#include <stdio.h>

int main()
{
    int fib[10];
    int i;

    // First two generations
    fib[0] = 1;
    fib[1] = 1;

    // Calculate remaining generations
    for (i = 2; i < 10; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // Display all 10 generations
    printf("Fibonacci Generations:\n");

    for (i = 0; i < 10; i++)
    {
        printf("Generation %d = %d\n", i + 1, fib[i]);
    }

    return 0;
}