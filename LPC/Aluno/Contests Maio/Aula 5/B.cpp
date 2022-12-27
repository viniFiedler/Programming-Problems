
#include <bits/stdc++.h>
using namespace std;

typedef struct level
{
    int vida, muni, ini;
    int maior, menor;
} level;

int main()
{
    int n;

    cin >> n;
    vector<level> vet;

    for (int i = 0; i < n; i++)
    {
        level aux;

        cin >> aux.vida >> aux.ini >> aux.muni;
        aux.menor = aux.menor = 1;
        vet.push_back(aux);
    }

    if (vet.size() == 1)
    {
        cout << "Easiest and Hardest is level 1" << endl;
        return 0;
    }

    int facil = 0, dificil = 0;
    for (int i = 0; i < vet.size(); i++)
    {
        // para o facil
        if (vet[i].vida > vet[facil].vida)
            facil = i;
        else if (vet[i].ini < vet[facil].ini)
            facil = i;
        else if (vet[i].muni > vet[facil].muni)
            facil = i;
        printf("%d %d\n", i, facil);
        // para o dificil
        if (vet[i].vida < vet[dificil].vida)
            dificil = i;
        else if (vet[i].ini > vet[dificil].ini)
            dificil = i;
        else if (vet[i].muni < vet[dificil].muni)
            dificil = i;
    }

    cout << "Easiest is level " << facil << endl;
    cout << "Hardest is level " << dificil << endl;
    return 0;
}