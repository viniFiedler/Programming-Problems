// https://cses.fi/problemset/task/1070
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int num;
    cin >> num;
    if (num == 2 || num == 3)
        cout << "NO SOLUTION\n";
    else
    {
        for (int i = num - 1; i > 0; i -= 2)
        {
            cout << i << " ";
        }
        for (int i = num; i > 0; i -= 2)
        {
            cout << i << " ";
        }

        cout << endl;
    }
    return 0;
}