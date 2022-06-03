// frogs 2

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;

    cin >> n >> k;
    vector<int> pedras;
    vector<int> somaDaPosicao;
    somaDaPosicao.push_back(0);
    for (int i = 0; i < n; i++)
    {
        int h;
        cin >> h;
        pedras.push_back(h);
    }

    int pos = n;
    int soma = 0;
    for (int i = 1; i < pos; i++)
    {

        int melhor = INT_MAX;
        int pula = k;
        if (i < pula)
            pula = i;

        while (pula)
        {
            if (somaDaPosicao[i - pula] + abs(pedras[i] - pedras[i - pula]) < melhor)
            {
                melhor = somaDaPosicao[i - pula] + abs(pedras[i] - pedras[i - pula]);
            }
            pula--;
        }

        somaDaPosicao.push_back(melhor);
    }

    cout << somaDaPosicao[pos - 1] << endl;

    return 0;
}