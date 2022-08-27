#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
int amigos[MAX];
int tam[MAX];

void init()
{
    for (int i = 0; i < MAX; i++)
    {
        amigos[i] = 0;
        tam[i] = 1;
    }
}

int find(int x)
{
    if (amigos[x] == x)
        return x;
    find(amigos[x]);
}

void merge(int u, int v)
{
    int a = find(u);
    int b = find(v);
    if (tam[a] > tam[b])
        swap(a, b);
    amigos[a] = b;
    tam[b] += tam[a];
}

int main()
{
    int testes;
    cin >> testes;

    while (testes--)
    {
        int nCriminosos, nLinhas;
        char opcao;
        cin >> nCriminosos >> nLinhas;
        for (int i = 0; i < nLinhas; i++)
        {
            int pA, pB;
            cin >> opcao >> pA >> pB;
        }
    }

    return 0;
}