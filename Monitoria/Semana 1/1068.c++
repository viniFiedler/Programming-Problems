// https://cses.fi/problemset/task/1068
#include <bits/stdc++.h>
using namespace std;

int main()
{

    long int n;
    cin >> n;
    cout << n << " ";
    while (n != 1)
    {
        if (!(n & 1))
            n /= 2;
        else
            n = n + n + n + 1;
        cout << n << " ";
    }
    cout << endl;

    return 0;
}