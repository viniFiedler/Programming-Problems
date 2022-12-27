#include <bits/stdc++.h>
using namespace std;
int main()
{
    int numero;

    do
    {
        cin >> numero;

        int i;
        int bits[32];
        int a[32], b[32];

        for (i = 0; numero > 0; i++)
        {
            bits[i] = numero % 2;
            numero = numero / 2;
        }
        int j;
        for (j = 0; j < i; j++)
        {

            if (j % 2 == 0)
                b[j] = bits[j];
            else
                b[]
        }

    } while (numero != 0);
}