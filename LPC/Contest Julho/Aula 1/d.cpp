#include <bits/stdc++.h>
using namespace std;
#define MAX 250000

int main()
{
    int n;
    string letras;
    string esperado;

    queue<char> filaLetra;
    queue<char> filaEsperado;

    cin >> n;
    cin >> letras;
    cout << letras;
    cin >> esperado;

    int tamanho = letras.size();

    for (int i = 0; i < tamanho; i++)
    {
        filaLetra.push(letras[tamanho - 1 - i]);
    }
    for (int i = 0; i < tamanho; i++)
    {
        filaEsperado.push(esperado[tamanho - 1 - i]);
    }

    for (int i = 0; i < n; i++)
    {
        char a = filaLetra.front();
        filaLetra.pop();
        filaLetra.push(a);
        if (filaLetra == filaEsperado)
        {
            cout << i + 1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}