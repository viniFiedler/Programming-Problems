// https://cses.fi/problemset/task/1083
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    long int sum = 1;
    cin >> n;

    while (n > 1)
    {
        int j;
        cin >> j;
        sum += n - j;
        n--;
    }

    cout << sum << endl;

    return 0;
}