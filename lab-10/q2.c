#include <stdio.h>

typedef struct {
    int roll;
    char name[15];
    int attended;
} Student;

int main() {
    FILE *fp = fopen("attendance.txt", "w");
    if (!fp) return 1;

    Student students[5] = {
        {1, "Ayesha", 18},
        {2, "Bilal", 14},
        {3, "Hamza", 20},
        {4, "Sana", 12},
        {5, "Zainab", 16}
    };

    for (int i = 0; i < 5; i++) {
        fprintf(fp, "%-3d %-15s %3d\n", students[i].roll, students[i].name, students[i].attended);
    }
    fclose(fp);

    fp = fopen("attendance.txt", "rb+");
    if (!fp) return 1;

    int roll;
    printf("Roll number: ");
    scanf("%d", &roll);

    fseek(fp, (roll - 1) * 24, SEEK_SET);
    Student s;
    fscanf(fp, "%d %s %d", &s.roll, s.name, &s.attended);
    float pct = (s.attended / 20.0) * 100;
    printf("%s: %d / 20 (%.1f%%)", s.name, s.attended, pct);
    if (pct < 75.0) printf(" Short attendance");
    printf("\n");

    int leaveRoll, leaves;
    printf("Roll number for leave: ");
    scanf("%d", &leaveRoll);
    printf("Lectures: ");
    scanf("%d", &leaves);

    fseek(fp, (leaveRoll - 1) * 24, SEEK_SET);
    fscanf(fp, "%d %s %d", &s.roll, s.name, &s.attended);
    s.attended += leaves;

    fseek(fp, (leaveRoll - 1) * 24, SEEK_SET);
    fprintf(fp, "%-3d %-15s %3d\n", s.roll, s.name, s.attended);

    pct = (s.attended / 20.0) * 100;
    printf("%s: now %d / 20 (%.1f%%)\n", s.name, s.attended, pct);

    fseek(fp, -24, SEEK_END);
    fscanf(fp, "%d %s %d", &s.roll, s.name, &s.attended);
    printf("Last record: %d %s %d\n", s.roll, s.name, s.attended);

    fclose(fp);
    return 0;
}
