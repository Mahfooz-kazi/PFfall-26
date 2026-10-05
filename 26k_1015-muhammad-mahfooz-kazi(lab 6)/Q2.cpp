#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
using namespace std;

int main()
{
    string pass[5];
    int bestScore = -100;
    int bestIndex = 0;
    int below10 = 0;

    for (int i = 0; i < 5; i++)
    {
        printf("Enter password %d: ", i + 1);
        cin >> pass[i];
    }

    for (int i = 0; i < 5; i++)
    {
        int score = 0;

        // one loop over the characters
        for (int j = 0; j < pass[i].length(); j++)
        {
            char c = pass[i][j];
            if (islower(c))
                score += 1;
            if (isupper(c))
                score += 2;
            if (isdigit(c))
                score += 3;
        }

        if (pass[i].length() >= 8)
            score += 5;
        if (pass[i].find("123") != string::npos)
            score -= 3;

        printf("%s -> %d\n", pass[i].c_str(), score);

        if (score > bestScore)
        {
            bestScore = score;
            bestIndex = i;
        }
        if (score < 10)
            below10++;
    }

    printf("Strongest: %s (%d)\n", pass[bestIndex].c_str(), bestScore);
    printf("Scored below 10: %d\n", below10);

    return 0;
}