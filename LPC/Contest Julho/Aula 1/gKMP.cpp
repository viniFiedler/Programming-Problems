#include <bits/stdc++.h>
using namespace std;
#define MAX 1000001
int a[MAX], n, m;
char S[MAX], P[MAX], tem[MAX];
int k;

void calculatePrefix()
{
    int i = 0, j = -1;
    a[0] = -1;
    while (i < m)
    {
        while (j >= 0 && P[i] != P[j])
            j = a[j];
        i++;
        j++;
        a[i] = j;
    }
}
int KMP()
{
    int i = 0, j = 0;
    // cout << " entrei " << i;
    calculatePrefix();
    while (i < n)
    {
        while (j >= 0 && S[i] != P[j])
            j = a[j];
        j++;
        i++;
        if (j == m)
            return i - m;
    }
    return -1;
}

int main()
{
    int tamanhoS;
    int tam;
    int teste;

    cin >> teste;
    while (teste--)
    {
        cin >> tamanhoS >> tam;
        cin >> S;

        int resposta = 0;
        memset(tem, 0, sizeof(tem));

        if (tam == tamanhoS)
        {
            cout << 1 << endl;
            continue;
        }

        for (k = 0; k <= tamanhoS - tam; k++)
        {
            memset(P, 0, sizeof(P));

            for (int f = 0; f < tam; f++)
            {
                P[f] = S[k + f];
            }
            // cout << P << endl;

            n = tamanhoS, m = tam;
            int flag = 1;
            int verdade = KMP();

            if (verdade != -1 && tem[verdade] == 0)
            {
                resposta++;
                tem[verdade] = tem[k] = 1;
            }
        }

        cout << resposta << endl;
        // for (int i = 0; i < n; i++)
        // {
        //     printf("tem[%d] %d ", i, tem[i]);
        // }
    }

    return 0;
}