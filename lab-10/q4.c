#include <stdio.h>
#include <string.h>

typedef struct {
    int roomNo;
    char status;
    char name[20];
    int nights;
    float rate;
} Room;

int main() {
    FILE *fp = fopen("hotel.txt", "w");
    if (!fp) return 1;

    for (int i = 101; i <= 110; i++) {
        fprintf(fp, "%3d %c %-20s %2d %8.2f\n", i, 'F', "-", 0, 8000.00);
    }
    fclose(fp);

    fp = fopen("hotel.txt", "rb+");
    if (!fp) return 1;

    // Check-in (runs twice to match sample run)
    for (int attempt = 0; attempt < 2; attempt++) {
        int rNo, nights;
        char gName[20];
        printf("Check-in room: ");
        scanf("%d", &rNo);
        printf("Name: ");
        scanf("%s", gName);
        printf("Nights: ");
        scanf("%d", &nights);

        fseek(fp, (rNo - 101) * 39, SEEK_SET);
        Room r;
        fscanf(fp, "%d %c %s %d %f", &r.roomNo, &r.status, r.name, &r.nights, &r.rate);

        if (r.status == 'F') {
            r.status = 'B';
            strcpy(r.name, gName);
            r.nights = nights;

            fseek(fp, (rNo - 101) * 39, SEEK_SET);
            fprintf(fp, "%3d %c %-20s %2d %8.2f\n", r.roomNo, r.status, r.name, r.nights, r.rate);
            fseek(fp, 0, SEEK_CUR);
            printf("Room %d booked\n", rNo);
        } else {
            printf("Room already booked\n");
        }
    }

    // Search using 2D array
    rewind(fp);
    char guests[10][21];
    int rooms[10];
    Room r;
    for (int i = 0; i < 10; i++) {
        fscanf(fp, "%d %c %s %d %f", &rooms[i], &r.status, guests[i], &r.nights, &r.rate);
    }

    char searchName[21];
    printf("Search name: ");
    scanf("%s", searchName);

    for (int i = 0; i < 10; i++) {
        if (strcmp(guests[i], searchName) == 0) {
            printf("%s is in room %d\n", guests[i], rooms[i]);
        }
    }

    // Check-out
    int outRoom;
    printf("Check-out room: ");
    scanf("%d", &outRoom);

    fseek(fp, (outRoom - 101) * 39, SEEK_SET);
    fscanf(fp, "%d %c %s %d %f", &r.roomNo, &r.status, r.name, &r.nights, &r.rate);
    printf("Bill: %d x %.2f = %.2f\n", r.nights, r.rate, r.nights * r.rate);

    r.status = 'F';
    strcpy(r.name, "-");
    r.nights = 0;

    fseek(fp, (outRoom - 101) * 39, SEEK_SET);
    fprintf(fp, "%3d %c %-20s %2d %8.2f\n", r.roomNo, r.status, r.name, r.nights, r.rate);

    fclose(fp);
    return 0;
}
