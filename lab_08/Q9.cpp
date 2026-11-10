#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Read 3 marks (0 to 100) and send them back to main
void readMarks(int &m1, int &m2, int &m3)
{
    do
    {
        cout << "  Enter mark 1 (0 to 100): ";
        cin >> m1;
        if (m1 < 0 || m1 > 100)
            cout << "  Marks must be from 0 to 100. Try again." << endl;
    } while (m1 < 0 || m1 > 100);

    do
    {
        cout << "  Enter mark 2 (0 to 100): ";
        cin >> m2;
        if (m2 < 0 || m2 > 100)
            cout << "  Marks must be from 0 to 100. Try again." << endl;
    } while (m2 < 0 || m2 > 100);

    do
    {
        cout << "  Enter mark 3 (0 to 100): ";
        cin >> m3;
        if (m3 < 0 || m3 > 100)
            cout << "  Marks must be from 0 to 100. Try again." << endl;
    } while (m3 < 0 || m3 > 100);
}

// 1. One function gives back four results
void calculateStats(int m1, int m2, int m3, int &total, double &average,
                    int &highest, int &lowest)
{
    total = m1 + m2 + m3;
    average = total / 3.0;

    highest = m1;
    if (m2 > highest) highest = m2;
    if (m3 > highest) highest = m3;

    lowest = m1;
    if (m2 < lowest) lowest = m2;
    if (m3 < lowest) lowest = m3;
}

// 2. Swap two marks
void swapMarks(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// 3. Add grace marks (only if mark is 35 to 39, up to 5, so the student passes)
void addGraceMarks(int &mark, int grace)
{
    if (mark >= 35 && mark <= 39)
    {
        mark = mark + grace;
        if (mark > 40)      // grace only helps the student reach 40
            mark = 40;
    }
}

// 4. Give back both a grade and a remark
void findGrade(double avg, char &grade, string &remarks)
{
    if (avg >= 75)
    {
        grade = 'A';
        remarks = "Excellent";
    }
    else if (avg >= 50)
    {
        grade = 'B';
        remarks = "Good";
    }
    else
    {
        grade = 'C';
        remarks = "Needs Improvement";
    }
}

// 6. Comparison demo
void incrementByValue(int x)
{
    x = x + 1;
}

void incrementByReference(int &x)
{
    x = x + 1;
}

int main()
{
    int m1, m2, m3;
    int total, highest, lowest, grace;
    double average;
    char grade;
    string remarks;

    // Teacher gives the grace marks (0 to 5)
    do
    {
        cout << "Enter grace marks to give (0 to 5): ";
        cin >> grace;
        if (grace < 0 || grace > 5)
            cout << "Grace must be from 0 to 5. Try again." << endl;
    } while (grace < 0 || grace > 5);

    // Table heading
    // (results are stored as text so the table can be printed after all input)
    string table = "";
    cout << fixed << setprecision(2);

    cout << "\n";
    // 5. Repeat for 5 students
    int roll;
    int marksList[5][3];
    int totals[5], highs[5], lows[5];
    double averages[5];
    char grades[5];
    string remarkList[5];

    for (roll = 0; roll < 5; roll++)
    {
        cout << "Student " << roll + 1 << ":" << endl;
        readMarks(m1, m2, m3);

        // grace marks
        addGraceMarks(m1, grace);
        addGraceMarks(m2, grace);
        addGraceMarks(m3, grace);

        // sort from highest to lowest using swapMarks
        if (m1 < m2) swapMarks(m1, m2);
        if (m2 < m3) swapMarks(m2, m3);
        if (m1 < m2) swapMarks(m1, m2);

        calculateStats(m1, m2, m3, total, average, highest, lowest);
        findGrade(average, grade, remarks);

        marksList[roll][0] = m1;
        marksList[roll][1] = m2;
        marksList[roll][2] = m3;
        totals[roll] = total;
        highs[roll] = highest;
        lows[roll] = lowest;
        averages[roll] = average;
        grades[roll] = grade;
        remarkList[roll] = remarks;
    }

    // Print the result table
    cout << "\n=========================== RESULT TABLE ===========================" << endl;
    cout << "Std\tMarks(High to Low)\tTotal\tAverage\tGrade\tRemark" << endl;
    cout << "--------------------------------------------------------------------" << endl;
    for (roll = 0; roll < 5; roll++)
    {
        cout << roll + 1 << "\t"
             << marksList[roll][0] << " " << marksList[roll][1] << " "
             << marksList[roll][2] << "\t\t"
             << totals[roll] << "\t"
             << averages[roll] << "\t"
             << grades[roll] << "\t"
             << remarkList[roll] << endl;
    }
    cout << "--------------------------------------------------------------------" << endl;

    cout << "\nHighest and lowest mark of each student:" << endl;
    for (roll = 0; roll < 5; roll++)
    {
        cout << "Student " << roll + 1 << ": highest = " << highs[roll]
             << ", lowest = " << lows[roll] << endl;
    }

    // 6. Comparison demo
    int x = 10;
    cout << "\n--- Pass by value vs pass by reference ---" << endl;
    cout << "Starting value of x: " << x << endl;

    incrementByValue(x);
    cout << "After incrementByValue(x): " << x << endl;

    incrementByReference(x);
    cout << "After incrementByReference(x): " << x << endl;

    // incrementByValue gets a copy of x, so the original x does not change.
    // incrementByReference works on x itself, so the original x becomes 11.

    return 0;
}
