#include <bits/stdc++.h>
using namespace std;
int pd[4][4];
int maiorPeso;
int pesoAlvo;
int soma;
// pd[somaDaPosicao][pesoDoNo] = quantas vezes passou pelo d
int procuraCaminho(int soma, int peso, bool passou)
{
    if (soma == 0 && passou)
    {
        return 1;
    }
    if (soma <= 0 || (soma == 0 && !passou))
    {
        return 0;
    }
    if (pd[soma][peso] != -1)
        return pd[soma][peso];

    pd[soma][peso] = 0;

    if (peso >= pesoAlvo)
    {
        passou = true;
    }

    for (int i = 1; i < maiorPeso; i++)
    {
        pd[soma][peso] += procuraCaminho(soma - peso, i, passou);
    }
}

int main()
{
    memset(pd, -1, sizeof(pd));

    cin >> soma >> maiorPeso >> pesoAlvo;
    cout << procuraCaminho(soma, 1, false);

    cout << endl;
}