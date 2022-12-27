#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int cartas;
    int casos;
    cin >> casos;
    for (int i = 0; i < casos; i++)
    {
        long long int soma = 5;
        int tamanho = 1;
        cin >> cartas;
        while (cartas > soma)
        {
            cartas -= soma;
            soma += 3;
            tamanho += 1;
        }
        cout << tamanho << "\n";
    }
    return 0;
}