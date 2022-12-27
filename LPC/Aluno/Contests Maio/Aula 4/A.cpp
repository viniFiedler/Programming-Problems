// New Year and Hurry

#include <bits/stdc++.h>
using namespace std;

int main()
{
    bool fica = true;
    int ano;
    scanf("%d", &ano);

    while (fica)
    {
        ano++;
        int unidade = ano % 10, dezena = (ano / 10) % 10, centena = (ano / 100) % 10, milhar = ano / 1000;
        if (unidade != dezena &&
            unidade != centena &&
            unidade != milhar &&
            centena != milhar &&
            centena != dezena &&
            dezena != milhar)
        {
            printf("%d\n", ano);
            return 0;
        }
    }

    return 0;
}