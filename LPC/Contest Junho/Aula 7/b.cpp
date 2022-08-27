// Cut Ribbon
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    int vet[n + 1][3];

    for (int i = 0; i < n + 1; i++)
    {
        vet[i][0] = INT_MIN;
        vet[i][2] = INT_MIN;
        vet[i][1] = INT_MIN;
    }

    vet[0][0] = vet[0][1] = vet[0][2] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a <= i)
        {
            int auxA = INT_MIN, auxB = INT_MIN, auxC = INT_MIN;

            if (vet[i - a][0] != INT_MIN)
            {
                auxA = vet[i - a][0] + 1;
            }
            if (vet[i - a][1] != INT_MIN)
            {
                auxB = vet[i - a][1] + 1;
            }
            if (vet[i - a][2] != INT_MIN)
            {
                auxC = vet[i - a][2] + 1;
            }

            vet[i][0] = max(auxA, max(auxB, auxC));
        }
        if (b <= i)
        {
            int auxA = INT_MIN, auxB = INT_MIN, auxC = INT_MIN;
            if (vet[i - b][0] != INT_MIN)
            {
                auxA = vet[i - b][0] + 1;
            }
            if (vet[i - b][1] != INT_MIN)
            {
                auxB = vet[i - b][1] + 1;
            }
            if (vet[i - b][2] != INT_MIN)
            {
                auxC = vet[i - b][2] + 1;
            }

            vet[i][1] = max(auxA, max(auxB, auxC));
        }
        if (c <= i)
        {
            int auxA = INT_MIN, auxB = INT_MIN, auxC = INT_MIN;
            if (vet[i - c][0] != INT_MIN)
            {

                auxA = vet[i - c][0] + 1;
            }
            if (vet[i - c][1] != INT_MIN)
            {
                auxB = vet[i - c][1] + 1;
            }
            if (vet[i - c][2] != INT_MIN)
            {
                auxC = vet[i - c][2] + 1;
            }

            vet[i][2] = max(auxA, max(auxB, auxC));
        }
    }

    int resultado = max(vet[n][0], max(vet[n][1], vet[n][2]));

    cout << resultado << endl;

    return 0;
}