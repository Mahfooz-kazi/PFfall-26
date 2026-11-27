#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char name[30];
    char classType;
    int health;
    int attack;
    int defense;
    int speed;
    float powerScore;
} Character;

void printCharacterCard(Character *c) {
    printf("=== CHARACTER CARD ===\n");
    printf("Name  : %s\n", c->name);
    printf("Class : %c\n", c->classType);
    printf("HP/ATK/DEF/SPD: %d/%d/%d/%d\n", c->health, c->attack, c->defense, c->speed);
    printf("Power Score: %.2f\n", c->powerScore);
}

void printRoster(Character *arr, int n) {
    printf("%-15s %-6s %-6s %-6s %-6s %-6s %-12s\n", "Name", "Class", "HP", "ATK", "DEF", "SPD", "Power");
    for(int i=0; i<n; i++) {
        printf("%-15s %-6c %-6d %-6d %-6d %-6d %-12.2f\n", arr[i].name, arr[i].classType, arr[i].health, arr[i].attack, arr[i].defense, arr[i].speed, arr[i].powerScore);
    }
}

int main() {
    int n;
    printf("Enter number of characters: ");
    scanf("%d", &n);
    Character chars[n];

    for(int i=0; i<n; i++) {
        do {
            printf("Enter name for character %d: ", i+1);
            scanf("%s", chars[i].name);
            int duplicate = 0;
            for(int j=0; j<i; j++) {
                if(strcasecmp(chars[i].name, chars[j].name) == 0) {
                    duplicate = 1;
                    printf("Duplicate name! Try again.\n");
                }
            }
            if(!duplicate) break;
        } while(1);

        printf("Enter class ('W', 'M', 'A'): ");
        scanf(" %c", &chars[i].classType);

        do {
            printf("Enter health (100-1000): ");
            scanf("%d", &chars[i].health);
        } while(chars[i].health < 100 || chars[i].health > 1000);

        do {
            printf("Enter attack (10-100): ");
            scanf("%d", &chars[i].attack);
        } while(chars[i].attack < 10 || chars[i].attack > 100);

        do {
            printf("Enter defense (10-100): ");
            scanf("%d", &chars[i].defense);
        } while(chars[i].defense < 10 || chars[i].defense > 100);

        do {
            printf("Enter speed (10-100): ");
            scanf("%d", &chars[i].speed);
        } while(chars[i].speed < 10 || chars[i].speed > 100);

        chars[i].powerScore = (chars[i].health * 0.3) + (chars[i].attack * 0.3) + (chars[i].defense * 0.2) + (chars[i].speed * 0.2);
    }

    int maxIdx = 0;
    for(int i=1; i<n; i++) {
        if(chars[i].powerScore > chars[maxIdx].powerScore) maxIdx = i;
    }
    printf("Highest Power Character: %s with score %.2f\n", chars[maxIdx].name, chars[maxIdx].powerScore);

    int warriors=0, mages=0, archers=0;
    for(int i=0; i<n; i++) {
        if(chars[i].classType == 'W') warriors++;
        else if(chars[i].classType == 'M') mages++;
        else if(chars[i].classType == 'A') archers++;

        if(chars[i].powerScore > 700 && chars[i].attack > 80) {
            printf("WARNING: Overpowered character -> %s\n", chars[i].name);
        }
    }
    printf("Counts -> Warriors: %d, Mages: %d, Archers: %d\n", warriors, mages, archers);

    printRoster(chars, n);
    printCharacterCard(&chars[maxIdx]);

    return 0;
}
