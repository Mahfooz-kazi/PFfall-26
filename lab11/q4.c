#include <stdio.h>

typedef struct {
    char deviceName[30];
    char deviceType;
    float powerRating;
    int isOn;
    int level;
    float hoursUsed;
} Device;

void toggleDevice(Device *d) {
    if (d->isOn) {
        d->isOn = 0;
        d->level = 0;
    } else {
        d->isOn = 1;
        d->level = 3;
    }
}

void setLevel(Device *d, int newLevel) {
    if (!d->isOn) {
        printf("Turn device ON first!\n");
        return;
    }
    if (newLevel >= 0 && newLevel <= 5) {
        d->level = newLevel;
    } else {
        printf("Level must be between 0 and 5.\n");
    }
}

float calculatePowerUsage(Device *d, float hours) {
    if (d->isOn) {
        return d->powerRating * hours * (d->level / 5.0);
    }
    return 0;
}

void updateHours(Device *d, float hours) {
    if (d->isOn) {
        d->hoursUsed += hours;
    }
}

void printDeviceStatus(Device *d) {
    printf("%s [%c] : %s (Level %d) : %.0fW : %.1f hrs\n", 
           d->deviceName, d->deviceType, d->isOn ? "ON" : "OFF", d->level, d->powerRating, d->hoursUsed);
}

void masterOff(Device *devices, int n) {
    Device *ptr = devices;
    for (int i = 0; i < n; i++) {
        (ptr + i)->isOn = 0;
        (ptr + i)->level = 0;
    }
}

int main() {
    int n;
    printf("Enter number of devices: ");
    scanf("%d", &n);
    Device devices[n];

    for(int i=0; i<n; i++) {
        printf("Enter name, type (L/F/C), power rating, isOn (0/1), level, hours used:\n");
        scanf("%s %c %f %d %d %f", devices[i].deviceName, &devices[i].deviceType, &devices[i].powerRating, &devices[i].isOn, &devices[i].level, &devices[i].hoursUsed);
    }

    int countOn = 0;
    float maxPower = -1;
    int maxPowerIdx = 0;
    float totalKWh = 0;

    Device *ptr = devices;
    for(int i=0; i<n; i++) {
        if((ptr + i)->isOn) countOn++;
        float usage = calculatePowerUsage(ptr + i, (ptr + i)->hoursUsed);
        totalKWh += usage / 1000.0;
        if(usage > maxPower) {
            maxPower = usage;
            maxPowerIdx = i;
        }
        printDeviceStatus(ptr + i);
    }

    printf("Total devices ON: %d\n", countOn);
    printf("Device consuming most power: %s\n", (ptr + maxPowerIdx)->deviceName);
    printf("Total daily energy cost (at Rs. 15/kWh): Rs. %.2f\n", totalKWh * 15.0);

    masterOff(devices, n);
    return 0;
}
