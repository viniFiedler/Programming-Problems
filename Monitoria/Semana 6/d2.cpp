#include <bits/stdc++.h>

int main()
{
    long int n, aux, resultado = 0;

    scanf("%ld", &n);

    aux = n % 6;

    if (aux == 1)
    {
        resultado = +1;
    }
    else if (aux == 2)
    {
        resultado = +2;
    }
    else if (aux == 3)
    {
        resultado = +4;
    }
    else if (aux == 4)
    {
        resultado = +8;
    }
    else if (aux == 5)
    {
        resultado = +16;
    }

    n -= aux;
    aux = (n / 6) * 32;
    resultado += aux;

    printf("%ld\n", resultado);

    return 0;
}