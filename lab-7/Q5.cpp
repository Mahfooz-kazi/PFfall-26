#include <iostream>
using namespace std;

int main()
{
    int marks[2][3][3];    // marks[class][student][subject]
    int total[2][3] = {0}; // total marks of each student

    // 1. Input marks
    for (int c = 0; c < 2; c++)
    {
        for (int s = 0; s < 3; s++)
        {
            for (int sub = 0; sub < 3; sub++)
            {
                cout << "Class " << c + 1 << ", Student " << s + 1
                     << ", Subject " << sub + 1 << " marks: ";
                cin >> marks[c][s][sub];
            }
        }
    }

    // 2. Total marks per student
    cout << "\nTotal Marks" << endl;
    for (int c = 0; c < 2; c++)
    {
        for (int s = 0; s < 3; s++)
        {
            for (int sub = 0; sub < 3; sub++)
            {
                total[c][s] += marks[c][s][sub];
            }
            cout << "Class " << c + 1 << ", Student " << s + 1
                 << ": " << total[c][s] << endl;
        }
    }

    // 3. Topper of each class
    cout << endl;
    for (int c = 0; c < 2; c++)
    {
        int top = 0;
        for (int s = 1; s < 3; s++)
        {
            if (total[c][s] > total[c][top])
            {
                top = s;
            }
        }
        cout << "Top Performer of Class " << c + 1 << ": Student "
             << top + 1 << " with " << total[c][top] << " marks" << endl;
    }

    // 4. Overall topper
    int topClass = 0, topStudent = 0;
    for (int c = 0; c < 2; c++)
    {
        for (int s = 0; s < 3; s++)
        {
            if (total[c][s] > total[topClass][topStudent])
            {
                topClass = c;
                topStudent = s;
            }
        }
    }

    // 5. Final result
    cout << "\nOverall Topper: Student " << topStudent + 1 << " of Class "
         << topClass + 1 << " with " << total[topClass][topStudent]
         << " marks" << endl;

    return 0;
}