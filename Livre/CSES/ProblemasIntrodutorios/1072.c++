// https://cses.fi/problemset/task/1072
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    cin >> n;
    {
        int x1, x2, y1, y2;
        x1 = x2 = y1 = y2 = 1;
        if (y1 == n + 1)
        {
            y1 = 1;
            x1++;
        }
    }

    return 0;
}