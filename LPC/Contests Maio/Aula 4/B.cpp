#include <bits/stdc++.h>
using namespace std;

int main()
{
    int vezes;
    scanf("%d", &vezes);
    int numero[100];

    for (int i = 0; i < vezes; i++)
    {
        int x;

        scanf("%d", &numero[i]);
        // printf("%d", x);
    }
    bool vetorDaVerdade[100];
    int par = 0;
    for (int i = 0; i < vezes; i++)
    {
        vetorDaVerdade[i] = numero[i] % 2;

        if (vetorDaVerdade[i])
            par++;
        else
            par--;
    }

    int cont = 0;
    for (int i = 0; i < vezes; i++)
    {

        if (par > 0)
        {
            if (!vetorDaVerdade[i])
            {
                printf("%d\n", i + 1);
                return 0;
            }
        }
        else if (vetorDaVerdade[i])
        {
            printf("%d\n", i + 1);
            return 0;
        }
    }
    return 0;
}