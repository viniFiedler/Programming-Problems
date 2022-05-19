#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[3];
    int testes;
    cin >> testes;
    int j;
    for (j = 1; j <= testes; j++)
    {
        int entrada;
        int posMaior = 0;
        int posMenor = 2;
        int i;
        for (i = 2; i >= 0; i--)
        {
            cin >> a[i];
        }

        for (i = 0; i < 3; i++)
        {
            if (a[i] < a[posMenor])
                posMenor = i;
            if (a[i] > a[posMaior])
                posMaior = i;
        }

        for (i = 0; i < 3; i++)
            if (i != posMenor && i != posMaior)
                cout << "Case " << j << ": " << a[i] << endl;
    }

    return 0;
}