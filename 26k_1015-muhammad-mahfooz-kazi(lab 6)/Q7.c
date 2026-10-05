#include <stdio.h>

int main()
{
    int num, original, reversed = 0, digit;

    printf("Enter a reference number: ");
    scanf("%d", &num);

    original = num;

    // Reverse the number
    while (num != 0)
    {
        digit = num % 10;
        reversed = reversed * 10 + digit;
        num = num / 10;
    }

    // Compare original and reversed
    if (original == reversed)
    {
        printf("Palindrome Confirmed");
    }
    else
    {
        printf("Not a Palindrome");
    }

    return 0;
}