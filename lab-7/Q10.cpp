#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    const int PASS_MARK = 40;

    int classes;
    int schoolTotalMarks = 0;
    double schoolAvgSum = 0; // sum of all student averages
    int schoolStudents = 0;

    cout << "Enter number of classes: ";
    cin >> classes;

    for (int c = 1; c <= classes; c++)
    {
        int students;
        int classTotalMarks = 0;
        double classAvgSum = 0; // sum of student averages in this class

        cout << "\nEnter number of students in Class " << c << ": ";
        cin >> students;

        for (int s = 1; s <= students; s++)
        {
            int subjects;
            int total = 0;
            bool failed = false;

            cout << "Enter number of subjects for Student " << s << ": ";
            cin >> subjects;

            for (int sub = 1; sub <= subjects; sub++)
            {
                int marks;
                cout << "Enter marks for Subject " << sub << ": ";
                cin >> marks;

                total += marks;
                if (marks < PASS_MARK)
                {
                    failed = true;
                }
            }

            double average = 0;
            if (subjects > 0)
            {
                average = (double)total / subjects;
            }

            cout << fixed << setprecision(2);
            cout << "Class " << c << ", Student " << s
                 << ": Total Marks = " << total
                 << ", Average = " << average
                 << ", Result = " << (failed ? "Fail" : "Pass") << endl;

            classTotalMarks += total;
            classAvgSum += average;
        }

        double classAverage = 0;
        if (students > 0)
        {
            classAverage = classAvgSum / students;
        }

        cout << endl;
        cout << "Class " << c << " Total Marks = " << classTotalMarks << endl;
        cout << "Class " << c << " Average = " << classAverage << endl;

        schoolTotalMarks += classTotalMarks;
        schoolAvgSum += classAvgSum;
        schoolStudents += students;
    }

    double schoolAverage = 0;
    if (schoolStudents > 0)
    {
        schoolAverage = schoolAvgSum / schoolStudents;
    }

    cout << "\nTotal Marks of all classes = " << schoolTotalMarks << endl;
    cout << "Overall School Average = " << schoolAverage << endl;

    return 0;
}