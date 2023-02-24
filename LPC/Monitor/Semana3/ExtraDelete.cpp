#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
int main()
{
    int prefixo[MAX];
    int sufixo[MAX];
    int sequencia[MAX];
    int testes;

    scanf("%d", &testes);

    while (testes--)
    {
        memset(sufixo, 0, sizeof(sufixo));
        memset(prefixo, 0, sizeof(testes));

        int tam;
        cin >> tam;
        int a;

        prefixo[0] = 1;
        for (int i = 1; i < tam; i++)
        {
            cin >> sequencia[i];

            // se os numeros estiverem em sequencia
            // e o anterior tbm estava
            if (prefixo[i - 1] && sequencia[i] > sequencia[i - 1])
            {
                prefixo[i - 1] = 1;
            }
        }
        sufixo[tam - 1] = 1;
        for (int i = tam - 2; i >= 0; i--)
        {
            if (sufixo[i + 1] && sequencia[i + 1] > sequencia[i])
            {
                prefixo[i] = 1;
            }
        }
    }

    return 0;
}