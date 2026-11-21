#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[20];
    float price;
    int stock;
} Item;

int main() {
    FILE *fp = fopen("items.txt", "w");
    if (!fp) return 1;

    Item initial_items[5] = {
        {1, "Rice", 250.00, 40},
        {2, "Sugar", 160.00, 25},
        {3, "Milk", 220.00, 30},
        {4, "CookingOil", 560.00, 12},
        {5, "Tea", 450.00, 18}
    };

    for (int i = 0; i < 5; i++) {
        fprintf(fp, "%-4d %-20s %9.2f %5d\n", initial_items[i].id, initial_items[i].name, initial_items[i].price, initial_items[i].stock);
    }
    fclose(fp);

    fp = fopen("items.txt", "rb+");
    if (!fp) return 1;

    int itemNo, qty;
    float totalBill = 0.0;

    while (1) {
        printf("Item no: ");
        scanf("%d", &itemNo);
        if (itemNo == 0) break;
        printf("Quantity: ");
        scanf("%d", &qty);

        fseek(fp, (itemNo - 1) * 42, SEEK_SET);
        Item cur;
        fscanf(fp, "%d %s %f %d", &cur.id, cur.name, &cur.price, &cur.stock);

        if (cur.stock >= qty) {
            printf("%s %d x %.2f = %.2f\n", cur.name, qty, cur.price, qty * cur.price);
            totalBill += qty * cur.price;
            cur.stock -= qty;

            fseek(fp, (itemNo - 1) * 42, SEEK_SET);
            fprintf(fp, "%-4d %-20s %9.2f %5d\n", cur.id, cur.name, cur.price, cur.stock);
            // Ensure file pointer updates correctly across read/write modes
            fseek(fp, 0, SEEK_CUR); 
        } else {
            printf("Only %d %s in stock\n", cur.stock, cur.name);
        }
    }

    printf("Total bill: %.2f\n", totalBill);
    fclose(fp);
    return 0;
}
```[cite: 1]

---

### Question #2: College Attendance
```c
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
```[cite: 1]

---

### Question #3: Weather Office
```c
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[10];
    float temp;
} City;

int main() {
    FILE *fp = fopen("temperature.txt", "w");
    if (!fp) return 1;

    City cities[5] = {
        {"Karachi", 32.5},
        {"Lahore", 30.1},
        {"Islamabad", 24.3},
        {"Quetta", 18.7},
        {"Peshawar", 28.9}
    };

    for (int i = 0; i < 5; i++) {
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
    scanf("%d", &newTemp); // Use %f in actual compilation, handled via scanf

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
```[cite: 1]

---

### Question #4: Hotel Rooms
```c
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

    // Check-in
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
        printf("Room %d booked\n", rNo);
    } else {
        printf("Room already booked\n");
    }

    // Search
    rewind(fp);
    char searchName[20];
    printf("Search name: ");
    scanf("%s", searchName);

    for (int i = 0; i < 10; i++) {
        fscanf(fp, "%d %c %s %d %f", &r.roomNo, &r.status, r.name, &r.nights, &r.rate);
        if (strcmp(r.name, searchName) == 0) {
            printf("%s is in room %d\n", r.name, r.roomNo);
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
```[cite: 1]

---

### Question #5: Expenses
```c
#include <stdio.h>

typedef struct {
    char category[12];
    float amount;
} Expense;

int main() {
    FILE *fp = fopen("expenses.txt", "w");
    if (!fp) return 1;

    Expense initial[4] = {
        {"Food", 1200.00},
        {"Transport", 500.00},
        {"Books", 850.00},
        {"Mobile", 300.00}
    };
    for(int i=0; i<4; i++) {
        fprintf(fp, "%-12s %9.2f\n", initial[i].category, initial[i].amount);
    }
    fclose(fp);

    // Append new expense
    char cat[12];
    float amt;
    printf("Category: ");
    scanf("%s", cat);
    printf("Amount: ");
    scanf("%f", &amt);

    fp = fopen("expenses.txt", "ab");
    fprintf(fp, "%-12s %9.2f\n", cat, amt);
    fclose(fp);

    // Read latest two & fix
    fp = fopen("expenses.txt", "rb+");
    fseek(fp, -2 * 23, SEEK_END);
    Expense e1, e2;
    fscanf(fp, "%s %f", e1.category, &e1.amount);
    fscanf(fp, "%s %f", e2.category, &e2.amount);
    printf("Latest two: %s %.2f, %s %.2f\n", e1.category, e1.amount, e2.category, e2.amount);

    int entryToFix;
    float newAmt;
    printf("Entry to fix: ");
    scanf("%d", &entryToFix);
    printf("Correct amount: ");
    scanf("%f", &newAmt);

    fseek(fp, (entryToFix - 1) * 23, SEEK_SET);
    fscanf(fp, "%s %f", e1.category, &e1.amount);
    e1.amount = newAmt;

    fseek(fp, (entryToFix - 1) * 23, SEEK_SET);
    fprintf(fp, "%-12s %9.2f\n", e1.category, e1.amount);

    rewind(fp);
    float total = 0;
    Expense temp;
    // Assuming 5 total entries now
    for(int i=0; i<5; i++) {
        if(fscanf(fp, "%s %f", temp.category, &temp.amount) == 2) {
            printf("%s %.2f\n", temp.category, temp.amount);
            total += temp.amount;
        }
    }
    printf("Total: %.2f\n", total);
    fclose(fp);
    return 0;
}
```[cite: 1]

---

### Question #6: Construction Towers (Recursion)
```c
#include <stdio.h>

void grow(int heights[], int n) {
    if (n == 0) return;
    grow(heights, n - 1);
    heights[n - 1] += (int)(heights[n - 1] * 0.10);
}

int tallest(int heights[], int n) {
    if (n == 1) return 0;
    int prevMax = tallest(heights, n - 1);
    return (heights[n - 1] > heights[prevMax]) ? (n - 1) : prevMax;
}

int search(int heights[], int n, int target) {
    if (n == 0) return -1;
    if (heights[n - 1] == target) return n - 1;
    return search(heights, n - 1, target);
}

int main() {
    int ids[6] = {101, 102, 103, 104, 105, 106};
    int heights[6] = {45, 120, 78, 200, 95, 150};

    grow(heights, 6);
    printf("New heights: ");
    for(int i=0; i<6; i++) printf("%d ", heights[i]);
    printf("\n");

    int tIdx = tallest(heights, 6);
    printf("Tallest: tower %d (%d m)\n", ids[tIdx], heights[tIdx]);

    int target;
    printf("Height to search: ");
    scanf("%d", &target);
    int sIdx = search(heights, 6, target);
    if(sIdx != -1) printf("Tower %d is %d m\n", ids[sIdx], target);
    else printf("Tower not found\n");

    return 0;
}
```[cite: 1]

---

### Question #7: Bank Transactions (Recursion)
```c
#include <stdio.h>

int finalBalance(int trans[], int n, int balance) {
    if (n == 0) return balance;
    return finalBalance(trans + 1, n - 1, balance + trans[0]);
}

int totalDeposits(int trans[], int n) {
    if (n == 0) return 0;
    int deposit = (trans[0] > 0) ? trans[0] : 0;
    return deposit + totalDeposits(trans + 1, n - 1);
}

int copyLarge(int trans[], int i, int n, int large[], int k) {
    if (i == n) return k;
    if (trans[i] <= -10000) {
        large[k] = trans[i];
        k++;
    }
    return copyLarge(trans, i + 1, n, large, k);
}

int main() {
    int startBalance = 20000;
    int trans[7] = {20000, -5000, -12000, 8000, -25000, -2500, 15000};
    int large[7];

    printf("Final balance: %d\n", finalBalance(trans, 7, startBalance));
    printf("Total deposits: %d\n", totalDeposits(trans, 7));

    int count = copyLarge(trans, 0, 7, large, 0);
    printf("Large withdrawals (%d): ", count);
    for(int i=0; i<count; i++) printf("%d ", large[i]);
    printf("\n");

    return 0;
}
```[cite: 1]

---

### Question #8: Hospital Health Score (Recursion)
```c
#include <stdio.h>

void buildScores(int change[], int score[], int i, int n, int current) {
    if (i == n) return;
    score[i] = current + change[i];
    buildScores(change, score, i + 1, n, score[i]);
}

int countLow(int score[], int n) {
    if (n == 0) return 0;
    return (score[0] < 50 ? 1 : 0) + countLow(score + 1, n - 1);
}

void reverse(int arr[], int left, int right) {
    if (left >= right) return;
    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
    reverse(arr, left + 1, right - 1);
}

int main() {
    int start = 70;
    int change[10] = {5, -8, -10, -12, 4, 6, 3, 7, -2, 5};
    int score[10];

    buildScores(change, score, 0, 10, start);
    
    printf("Daily scores: ");
    for(int i=0; i<10; i++) printf("%d ", score[i]);
    printf("\n");

    printf("Days below 50: %d\n", countLow(score, 10));

    reverse(score, 0, 9);
    printf("Latest first: ");
    for(int i=0; i<10; i++) printf("%d ", score[i]);
    printf("\n");

    return 0;
}
```[cite: 1]

---

### Question #9: Weather Grid Frost Zones (Flood Fill)
```c
#include <stdio.h>

int markZone(char map[5][5], int r, int c, char label) {
    if (r < 0 || r >= 5 || c < 0 || c >= 5 || map[r][c] != '*') return 0;
    map[r][c] = label;
    return 1 + markZone(map, r + 1, c, label)
             + markZone(map, r - 1, c, label)
             + markZone(map, r, c + 1, label)
             + markZone(map, r, c - 1, label);
}

int main() {
    float temp[5][5] = {
        { 2.1, -1.5, -2.0,  3.0,  4.2},
        { 1.8, -0.5,  2.5,  3.1, -1.0},
        { 3.3,  2.0,  1.5, -0.8, -2.0},
        {-1.2,  3.4,  4.0,  3.8, -0.6},
        {-2.5, -3.1,  5.1,  6.0,  4.7}
    };

    char map[5][5];
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            map[i][j] = (temp[i][j] < 0) ? '*' : '.';
        }
    }

    char label = 'A';
    int totalZones = 0;

    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            if(map[i][j] == '*') {
                int size = markZone(map, i, j, label);
                printf("Zone %c: %d stations\n", label, size);
                label++;
                totalZones++;
            }
        }
    }

    printf("Total zones: %d\n\n", totalZones);
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }

    return 0;
}
```[cite: 1]

---

### Question #10: String Compression & Expansion
```c
#include <stdio.h>
#include <string.h>

int countRepeat(char s[], int i) {
    if (s[i] == '\0' || s[i] != s[i + 1]) return 1;
    return 1 + countRepeat(s, i + 1);
}

void compress(char s[], int i, char out[], int j) {
    if (s[i] == '\0') {
        out[j] = '\0';
        return;
    }
