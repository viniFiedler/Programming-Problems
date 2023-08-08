#include <bits/stdc++.h>
using namespace std;
int vetor[12];

int resolve(int num)
{
    int minimo = num;
    for (int i = 0; i < 10; i++)
    {
        if (vetor[i] && vetor[i + 1] && !vetor[i + 2])
        {
            vetor[i] = 0;
            vetor[i + 1] = 0;
            vetor[i + 2] = 1;
            minimo = min(resolve(num - 1), minimo);
            vetor[i] = 1;
            vetor[i + 1] = 1;
            vetor[i + 2] = 0;
        }
    }

    for (int i = 2; i < 12; i++)
    {
        if (vetor[i] && vetor[i - 1] && !vetor[i - 2])
        {
            vetor[i] = 0;
            vetor[i - 1] = 0;
            vetor[i - 2] = 1;
            minimo = min(resolve(num - 1), minimo);
            vetor[i] = 1;
            vetor[i - 1] = 1;
            vetor[i - 2] = 0;
        }
    }

    return (minimo);
}

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        for (int i = 0; i < 12; i++)
        {
            vetor[i] = 0;
        }
        int pedra = 0;
        for (int i = 0; i < 12; i++)
        {
            char c;
            cin >> c;
            if (c == 'o')
            {
                vetor[i] = 1;
                pedra++;
            }
        }

        cout << resolve(pedra) << "\n";
    }

    return 0;
}