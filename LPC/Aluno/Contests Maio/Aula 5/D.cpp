// Game Store

#include <bits/stdc++.h>

using namespace std;

typedef struct Postos
{
    int dist, gas;
} Postos;

int calcula(vector<Postos> vet, int dist, int gas)
{
    if (dist > gas)
        return 0;

    calcula(vet, dist)
}
int main()
{
    int t, n, i, DistCaminhao, Gasosa, cont;
    cin >> t;
    while (t--)
    {
        cont = 0;
        vector<Postos> vet;
        Postos aux;
        cin >> n;
        for (i = 0; i < n; i++)
        {
            cin >> aux.dist >> aux.gas;
            vet.push_back(aux);
        }
        cin >> DistCaminhao >> Gasosa;
        for (i = vet.size() - 1; i >= 0; i--)
        {
        }
    }
}