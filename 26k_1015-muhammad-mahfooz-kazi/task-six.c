#include <stdio.h>

int main()
{
    int category, subtype, delayed;

    printf("Select Category:\n");
    printf("1. Greeting\n");
    printf("2. Query\n");
    printf("3. Complaint\n");
    printf("4. Feedback\n");
    printf("Enter category: ");
    scanf("%d", &category);

    if (category == 1)
    {
        printf("1. Morning\n");
        printf("2. Evening\n");
        printf("Enter sub-type: ");
        scanf("%d", &subtype);

        if (subtype == 1)
            printf("Good morning! How can I help you?\n");
        else if (subtype == 2)
            printf("Good evening! How can I help you?\n");
        else
            printf("Invalid selection.\n");
    }
    else if (category == 2)
    {
        printf("1. Product\n");
        printf("2. Billing\n");
        printf("3. Technical\n");
        printf("Enter sub-type: ");
        scanf("%d", &subtype);

        if (subtype == 1)
            printf("How can I help you with the product?\n");
        else if (subtype == 2)
            printf("How can I help you with billing?\n");
        else if (subtype == 3)
            printf("How can I help you with the technical issue?\n");
        else
            printf("Invalid selection.\n");
    }
    else if (category == 3)
    {
        printf("1. Delivery\n");
        printf("2. Quality\n");
        printf("Enter sub-type: ");
        scanf("%d", &subtype);

        if (subtype == 1)
        {
            printf("Is your order delayed? (1=Yes, 0=No): ");
            scanf("%d", &delayed);

            if (delayed == 1)
                printf("We sincerely apologize for the delay in your order.\n");
            else if (delayed == 0)
                printf("We apologize for the delivery issue.\n");
            else
                printf("Invalid selection.\n");
        }
        else if (subtype == 2)
        {
            printf("We apologize for the quality issue.\n");
        }
        else
        {
            printf("Invalid selection.\n");
        }
    }
    else if (category == 4)
    {
        printf("1. Positive\n");
        printf("2. Negative\n");
        printf("Enter sub-type: ");
        scanf("%d", &subtype);

        if (subtype == 1)
            printf("Thank you for your positive feedback!\n");
        else if (subtype == 2)
            printf("Thank you for your feedback. We will work to improve.\n");
        else
            printf("Invalid selection.\n");
    }
    else
    {
        printf("Invalid selection.\n");
    }

    return 0;
}