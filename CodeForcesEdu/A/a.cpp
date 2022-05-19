#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    list<int> inteiro;

    for (int i = 0; i < n; i++)
    {
        int numero;
        cin >> numero;
        inteiro.push_back(numero);
    }
    inteiro.sort();

    int cont = 0;
    for (int i = 0; i < n / 2; i++)
    {
        cont -= inteiro.front();
        inteiro.pop_front();
        cont += inteiro.front();
        inteiro.pop_front();
    }

    cout << cont << endl;

    return 0;
}