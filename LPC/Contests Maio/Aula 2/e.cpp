#include <bits/stdc++.h>

using namespace std;

int main()
{
    int numBarras[1001];
    for (int i = 0; i < 1001; i++)
        numBarras[i] = 0;

    int num, barra;
    cin >> num;

    while (num--)
    {
        cin >> barra;
        numBarras[barra]++;
    }

    int maior = 0, pilhas = 0;

    for (int i = 0; i < 1001; i++)
    {
        if (numBarras[i] >= 1)
            pilhas++;
        if (numBarras[i] > maior)
        {
            maior = numBarras[i];
        }
    }

    printf("%d %d\n", maior, pilhas);

    return 0;
}