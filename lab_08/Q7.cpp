#include <iostream>
using namespace std;

// Find the highest mark
int findMax(int *p, int n)
{
    int max = *p;
    for (int i = 1; i < n; i++)
    {
        if (*(p + i) > max)
            max = *(p + i);
    }
    return max;
}

// Find the lowest mark
int findMin(int *p, int n)
{
    int min = *p;
    for (int i = 1; i < n; i++)
    {
        if (*(p + i) < min)
            min = *(p + i);
    }
    return min;
}

// Find the average mark
double findAverage(int *p, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum = sum + *(p + i);
    return (double)sum / n;
}

// Count students above average
int countAbove(int *p, int n, double avg)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (*(p + i) > avg)
            count++;
    }
    return count;
}

// Reverse the array using two pointers
void reverseArray(int *p, int n)
{
    int *start = p;
    int *end = p + n - 1;
    int temp;

    while (start < end)
    {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

// Search for a mark, return position or -1
int searchMark(int *p, int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (*(p + i) == key)
            return i;
    }
    return -1;
}

// Print the array
void printArray(int *p, int n)
{
    for (int i = 0; i < n; i++)
        cout << *(p + i) << " ";
    cout << endl;
}

int main()
{
    int marks[10];
    int i, key, position, passCount = 0;

    // 1. Read marks (0 to 100 only)
    for (i = 0; i < 10; i++)
    {
        do
        {
            cout << "Enter marks of student " << i + 1 << " (0 to 100): ";
            cin >> marks[i];
            if (marks[i] < 0 || marks[i] > 100)
                cout << "Marks must be from 0 to 100. Try again." << endl;
        } while (marks[i] < 0 || marks[i] > 100);
    }

    // 2. Class result
    int highest = findMax(marks, 10);
    int lowest = findMin(marks, 10);
    double average = findAverage(marks, 10);
    int above = countAbove(marks, 10, average);

    cout << "\nHighest mark : " << highest << endl;
    cout << "Lowest mark  : " << lowest << endl;
    cout << "Average      : " << average << endl;
    cout << "Students above average: " << above << endl;

    // 6. Pass count (40 or more)
    for (i = 0; i < 10; i++)
    {
        if (marks[i] >= 40)
            passCount++;
    }
    cout << "Students who passed (40 or more): " << passCount << endl;

    // 4. Search for a mark
    cout << "\nEnter a mark to search: ";
    cin >> key;
    position = searchMark(marks, 10, key);
    if (position == -1)
        cout << "Mark " << key << " not found." << endl;
    else
        cout << "Mark " << key << " found at position " << position
             << " (roll number " << position + 1 << ")." << endl;

    // 5. Print before and after reversing
    cout << "\nMarks before reversing: ";
    printArray(marks, 10);

    // 3. Reverse
    reverseArray(marks, 10);

    cout << "Marks after reversing : ";
    printArray(marks, 10);

    return 0;
}
