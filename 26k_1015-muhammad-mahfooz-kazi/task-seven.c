#include <stdio.h>

int main()
{
    int stream, interest, medicine;

    printf("Enter stream (1=Science, 2=Commerce, 3=Arts): ");
    scanf("%d", &stream);

    switch (stream)
    {
    case 1:
        printf("Enter interest (1=Biology, 2=Physics, 3=Chemistry): ");
        scanf("%d", &interest);

        switch (interest)
        {
        case 1:
            printf("Interested in Medicine? (1=Yes, 0=No): ");
            scanf("%d", &medicine);

            if (medicine == 1)
                printf("Recommended Course: MBBS");
            else if (medicine == 0)
                printf("Recommended Course: Biotechnology");
            else
                printf("Invalid choice.");
            break;

        case 2:
            printf("Recommended Course: BS Physics");
            break;

        case 3:
            printf("Recommended Course: BS Chemistry");
            break;

        default:
            printf("Invalid choice.");
        }
        break;

    case 2:
        printf("Enter interest (1=Accounting, 2=Marketing): ");
        scanf("%d", &interest);

        switch (interest)
        {
        case 1:
            printf("Recommended Course: BS Accounting");
            break;

        case 2:
            printf("Recommended Course: BS Marketing");
            break;

        default:
            printf("Invalid choice.");
        }
        break;

    case 3:
        printf("Enter interest (1=Literature, 2=History, 3=Psychology): ");
        scanf("%d", &interest);

        switch (interest)
        {
        case 1:
            printf("Recommended Course: BS Literature");
            break;

        case 2:
            printf("Recommended Course: BS History");
            break;

        case 3:
            printf("Recommended Course: BS Psychology");
            break;

        default:
            printf("Invalid choice.");
        }
        break;

    default:
        printf("Invalid choice.");
    }

    return 0;
}