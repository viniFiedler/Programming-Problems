// https://codeforces.com/problemset/problem/1485/A
#include <bits/stdc++.h>
using namespace std;
int contador = INT_MAX;

// log 10^9 na base 2 =~ 30;
// portantanto desde que o b seja > 1, a pior solucao é de 30 passos

void testa(int cont, int a, int b)
{
    cont++;
    if (a / b == 0 || cont > contador)
    {
        if (cont < contador)
            contador = cont;
        return;
    }

    testa(cont, a / b, b);
    testa(cont, a, b + 1);
}

int main()
{
    int testes;
    scanf("%d", &testes);

    while (testes--)
    {
        contador = INT_MAX;
        int a, b;

        scanf("%d %d", &a, &b);
        if (b == 1)
        {
            testa(1, a, b + 1);
        }
        else
        {
            testa(0, a, b);
        }
        printf("%d\n", contador);
    }
    return 0;
}
