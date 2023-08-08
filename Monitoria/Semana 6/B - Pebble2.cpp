#include <bits/stdc++.h>
using namespace std;
int vetor[23];
int dp[8388608];

int codifica()
{
    int num = 0;
    for (int i = 0; i < 23; i++)
    {
        if (vetor[i])
        {
            num += 1 << i;
        }
    }

    return num;
}

int resolve(int num)
{
    int hash = codifica();
    int minimo = num;

    if (dp[hash] != -1)
        return dp[hash];
    for (int i = 0; i < 21; i++)
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

    for (int i = 2; i < 23; i++)
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
    dp[hash] = minimo;
    return (minimo);
}

int main()
{
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    while (n--)
    {
        for (int i = 0; i < 23; i++)
        {
            vetor[i] = 0;
        }
        int pedra = 0;
        for (int i = 0; i < 23; i++)
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