#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int distanciaPossivel(vector<long long int> estabulos, int n, int vacas, long long int meio)
{
    int numVacas = 1;
    long long int v = estabulos[0];
    for (int i = 1; i < n; i++)
    {
        if (estabulos[i] - v >= meio)
        {
            numVacas++;
            v = estabulos[i];
            if (numVacas == vacas)
            {
                break;
            }
        }
    }
    if (numVacas >= vacas)
    {
        return 1;
    }
    return 0;
}
int main()
{
    int numEstabulos, vacas, testes;
    long long int num;
    vector<long long int> estabulos;
    cin >> testes;
    while (testes--)
    {
        cin >> numEstabulos >> vacas;
        for (int i = 0; i < numEstabulos; i++)
        {
            cin >> num;
            estabulos.push_back(num);
        }

        sort(estabulos.begin(), estabulos.end());

        long long int menor = 1, maior = estabulos[numEstabulos - 1] - estabulos[0], meio;

        while (menor <= maior)
        {
            meio = (menor + maior) / 2;

            if (distanciaPossivel(estabulos, numEstabulos, vacas, meio))
            {
                menor = meio + 1;
            }
            else
            {
                maior = meio - 1;
            }
        }
        cout << maior << "\n";
    }

    return 0;
}