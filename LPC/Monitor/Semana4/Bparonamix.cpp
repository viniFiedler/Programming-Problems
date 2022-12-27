// https://codeforces.com/problemset/problem/80/A?locale=en
#include <bits/stdc++.h>
using namespace std;
// exercicio de forca bruta, possivel apenas pela entrada pequena e grande tempo (como o algoritimo é O(raiz(n)!) )

// a funcao ehPrimo retorna 1 se for primo e se nao for retorna 0
// como o problema pressupoe que apenas numeros com menos de 10.000 digitos serao
// inseridos, pode usar a regra da raiz quadrada para descobrir se o numero eh primo ou nao
int ehPrimo(int num)
{
    // se estir uma raiz quadrada natural entao ja nao eh primo
    float raiz = sqrtf(num);
    if (raiz == int(raiz))
        return 0;

    // verifica todos os numeros divisores
    else
    {
        int i = int(raiz);
        for (; i >= 2; i--)
        {
            if (num % i == 0)
                return 0;
        }
        return 1;
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    // se M nao for primo ja retorna
    if (!ehPrimo(m))
    {
        printf("NO\n");
        return 0;
    };

    // testa todos os numeros de M ate N, se houver algum primo retorno NO
    for (int i = m - 1; i > n; i--)
    {
        if (ehPrimo(i))
        {
            printf("NO\n");
            return 0;
        }
    }

    // se nao Retorna YESs
    printf("YES\n");
    return 0;
}
