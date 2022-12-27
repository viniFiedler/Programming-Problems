#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int main()
{

    int tamanho;
    cin >> tamanho;
    int tamanhoMetade = tamanho / 2;
    int elevado = (int)pow(10, tamanho);
    int elevadoMetade = (int)pow(10, tamanho / 2);
    int cont = 0,
        numero = 0;

    for (; numero < elevado; numero++)
    {
        int metade1 = numero / elevadoMetade;
        int metade2 = numero % elevadoMetade;
        int soma1 = 0, soma2 = 0;

        int i;

        for (i = 0; i < tamanhoMetade; i++)
        {
            soma1 += metade1 % 10;
            metade1 = metade1 / 10;
            soma2 += metade2 % 10;
            metade2 = metade2 / 10;
        }
        if (soma1 == soma2)
            cont++;
    }

    cout << cont << endl;

    return 0;
}