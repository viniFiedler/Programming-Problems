#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;
    int memoria[s.length() + 1][t.length() + 1];
    for (int i = 0; i <= s.length(); i++)
    {
        for (int j = 0; j <= t.length(); j++)
        {
            if (j == 0 || i == 0)
            {
                memoria[i][j] = 0;
            }

            else if (s[i - 1] == t[j - 1])
            {
                // printf("igual = %c %d %d\n", s[i - 1], i, j);
                memoria[i][j] = memoria[i - 1][j - 1] + 1;
            }
            else
            {
                memoria[i][j] = max(memoria[i - 1][j], memoria[i][j - 1]);
            }
        }
    }

    int i = s.length(), j = t.length();
    string palavra;

    while (i && j)
    {
        if (memoria[i][j - 1] == memoria[i - 1][j] && memoria[i][j] > memoria[i - 1][j])
        {

            palavra.insert(palavra.begin(), s[i - 1]);
            i--;
            j--;
        }

        else if (memoria[i][j - 1] == memoria[i - 1][j] && memoria[i][j] == memoria[i - 1][j])
        {
            i--;
        }

        else if (memoria[i - 1][j] > memoria[i][j - 1])
        {

            i--;
        }

        else if (memoria[i][j - 1] > memoria[i - 1][j])
        {
            j--;
        }
    }

    cout << palavra << endl;

    return 0;
}