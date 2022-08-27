// Cumulative Sum Query

#include <bits/stdc++.h>
using namespace std;
long int maior = 0;

typedef struct produto
{
    long int valor;
    long int peso;
} produto;

vector<produto> lista;

void maiorRecursivo(long int valorRestante, int posicao, long int maxLocal)
{
    if (lista[posicao].valor > valorRestante)
        return;
    if (posicao > lista.size() - 1)
    {
        valorRestante -= lista[posicao].valor;
    }
    maxLocal += lista[posicao].peso;

    if (maxLocal > maior)
        maior = maxLocal;

    maiorRecursivo(valorRestante, posicao++, maxLocal);
}

int main()
{
    int N, W;
    cin >> N >> W;

    for (int i = 0; i < N; i++)
    {
        produto aux;
        cin >> aux.valor >> aux.peso;
        lista.push_back(aux);
    }

    return 0;
}