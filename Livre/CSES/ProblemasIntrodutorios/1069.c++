// https://cses.fi/problemset/task/1069
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string sequence;

    cin >> sequence;
    int max = 0;
    int num = 0;
    char letra = sequence[0];
    for (auto &letter : sequence)
    {
        if (letra == letter)
        {
            num++;
            if (num > max)
            {
                max = num;
            }
        }
        else
        {
            num = 1;
            letra = letter;
        }
    }

    cout << max << endl;

    return 0;
}