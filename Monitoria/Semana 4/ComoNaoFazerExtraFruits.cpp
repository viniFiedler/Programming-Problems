#include <bits/stdc++.h>
using namespace std;

// tente rodar no seu computador e me conte quanto tempo levou o caso de n = 40

int somaTotal = 0;
int tamanho = 0;
int frutas[41];

void contaFruta(int pos, int soma)
{
    if (pos > tamanho)
        return;

    soma += frutas[pos];

    for (int i = pos + 1; i <= tamanho; i++)
    {
        contaFruta(i, soma);
    }

    if (soma >= 200)
        somaTotal += soma;
}

int main()
{
    cin >> tamanho;

    frutas[0] = 0;

    for (int i = 1; i <= tamanho; i++)
    {
        cin >> frutas[i];
    }

    contaFruta(0, somaTotal);

    cout << somaTotal << "\n";

    return 0;
}