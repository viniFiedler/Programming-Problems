#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k, n;
    scanf("%d %d", &n, &k);
    int cont = 0;
    set<long int> numeros;
    vector<long int> teste;
    int i = n - 1;
    if (k == 0)
        cout << n - 1 << endl;
    else
    {
        while (n--)
        {
            long int x;
            cin >> x;
            auto posTeste = numeros.find(x);
            if (posTeste != numeros.end())
                cont++;
            else
                numeros.insert(x);
            teste.push_back(x);
        }
        while (i >= 0)
        {
            long int valor = abs(teste[i] - k);

            auto pos = numeros.find(valor);

            if (pos != numeros.end() && teste[i] != valor)
            {
                cont++;
                // printf("numero = %ld alvo = %ld\n", teste[i], valor);
            }

            i--;
        }
        cout << cont << endl;
    }

    return 0;
}