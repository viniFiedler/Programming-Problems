#include <bits/stdc++.h>
using namespace std;

// linha Academia [ dia 1] [ dia 2] [ dia 3]
// linha Contest  [ dia 1] [ dia 2] [ dia 3]
// linha Descanco [ dia 1] [ dia 2] [ dia 3]

int main()
{
    int memo[100][3];
    int dia[100];

    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int aux;
        cin >> aux;
        dia[i] = aux;
    }

    memset(memo, 9999, sizeof(memo));
    if (dia[0] == 0)
    {
        memo[0][2] = 1;
    }
    else if (dia[0] == 1)
    {
        memo[0][1] = 0;
        memo[0][2] = 1;
    }
    else if (dia[0] == 2)
    {
        memo[0][0] = 0;
        memo[0][2] = 1;
    }
    else if (dia[0] == 3)
    {
        memo[0][0] = 0;
        memo[0][1] = 0;
        memo[0][2] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        // n acad / n contest
        if (dia[i] == 0)
        {
            memo[i][2] = min(memo[i - 1][0], min(memo[i - 1][1], memo[i - 1][2])) + 1;
        }
        // n acad / sim contest
        else if (dia[i] == 1)
        {
            memo[i][1] = min(memo[i - 1][0], memo[i - 1][2]);
            memo[i][2] = min(memo[i - 1][0], min(memo[i - 1][1], memo[i - 1][2])) + 1;
        }

        // sim contest // n contest
        else if (dia[i] == 2)
        {
            memo[i][0] = min(memo[i - 1][1], memo[i - 1][2]);
            memo[i][2] = min(memo[i - 1][0], min(memo[i - 1][1], memo[i - 1][2])) + 1;
        }

        else if (dia[i] == 3)
        {
            memo[i][0] = min(memo[i - 1][1], memo[i - 1][2]);
            memo[i][1] = min(memo[i - 1][0], memo[i - 1][2]);
            memo[i][2] = min(memo[i - 1][0], min(memo[i - 1][1], memo[i - 1][2])) + 1;
        }
    }

    cout << min(memo[n - 1][0], min(memo[n - 1][1], memo[n - 1][2])) << endl;

    return 0;
}