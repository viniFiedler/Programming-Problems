#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c;
    while (cin >> a >> b)
    {
        c = a + b;
        int i;

        for (i = 0; c > 0; i++)
        {
            c = c / 10;
        }

        cout << i << endl;
    }
    return 0;
}