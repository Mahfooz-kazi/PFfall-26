#include <stdio.h>
#include <string.h>

typedef struct {
    char name[10];
    float temp;
} City;

int main() {
    FILE *fp = fopen("temperature.txt", "w");
    if (!fp) return 1;

    City cities[5];
    for (int i = 0; i < 5; i++) {
        printf("Enter city %d name and temperature: ", i + 1);
        scanf("%s %f", cities[i].name, &cities[i].temp);
        fprintf(fp, "%-10s %5.1f\n", cities[i].name, cities[i].temp);
    }
    fclose(fp);

    fp = fopen("temperature.txt", "rb+");
    if (!fp) return 1;

    int cNum;
    printf("City number: ");
    scanf("%d", &cNum);

    fseek(fp, (cNum - 1) * 17, SEEK_SET);
    City c;
    fscanf(fp, "%s %f", c.name, &c.temp);
    printf("%s %.1f\n", c.name, c.temp);

    int updateNum;
    float newTemp;
    printf("City number to correct: ");
    scanf("%d", &updateNum);
    printf("New temperature: ");
    scanf("%f", &newTemp);

    fseek(fp, (updateNum - 1) * 17, SEEK_SET);
    fscanf(fp, "%s %f", c.name, &c.temp);
    c.temp = newTemp;

    fseek(fp, (updateNum - 1) * 17, SEEK_SET);
    fprintf(fp, "%-10s %5.1f\n", c.name, c.temp);
    printf("%s updated to %.1f\n", c.name, c.temp);

    rewind(fp);
    char hottest[10];
    float maxTemp = -999.0;
    for (int i = 0; i < 5; i++) {
        fscanf(fp, "%s %f", c.name, &c.temp);
        if (c.temp > maxTemp) {
            maxTemp = c.temp;
            strcpy(hottest, c.name);
        }
    }
    printf("Hottest city: %s (%.1f)\n", hottest, maxTemp);

    fclose(fp);
    return 0;
}
