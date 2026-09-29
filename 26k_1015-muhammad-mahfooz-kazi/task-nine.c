#include <stdio.h>

int main()
{
    int permissions;

    printf("Enter permissions: ");
    scanf("%d", &permissions);

    // Detect individual permission bits
    if (permissions & 1)
        printf("READ detected\n");

    if (permissions & 2)
        printf("WRITE detected\n");

    if (permissions & 4)
        printf("EXECUTE detected\n");

    if (permissions & 8)
        printf("DELETE detected\n");

    if (permissions & 16)
        printf("ADMIN detected\n");

    // Decide access
    if (permissions & 16)
        printf("Access: Full access: admin\n");

    else if ((permissions & 8) && (permissions & 2))
        printf("Access: delete and write\n");

    else if ((permissions & 4) && !(permissions & 2))
        printf("Access: execute only\n");

    else if ((permissions & 1) && !(permissions & 2) && !(permissions & 4))
        printf("Access: read-only\n");

    else if (!(permissions & 1) && !(permissions & 2) &&
             !(permissions & 4) && !(permissions & 8) && !(permissions & 16))
        printf("Access denied\n");

    else
        printf("Access: custom permissions\n");

    return 0;
}