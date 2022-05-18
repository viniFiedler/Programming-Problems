#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;

    cin >> n;
    cin >> k;

    int resolvidos = 0;
    int restante = 240 - k;

    for (int i = 1; i <= n && restante; i++)
    {
        if (restante - 5 * i >= 0)
        {
            restante -= 5 * i;
            resolvidos++;
        }
    }

    cout << resolvidos << endl;
    return 0;
}