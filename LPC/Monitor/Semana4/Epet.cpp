#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a = 0;
    int maior;
    for (int i = 0; i < 5; i++)
    {
        int c[4];
        scanf("%d %d %d %d", &c[0], &c[1], &c[2], &c[3]);
        int soma = c[0] + c[1] + c[2] + c[3];
        if (a < soma)
        {
            maior = i + 1;
            a = soma;
        }
    }
    printf("%d %d\n", maior, a);
    return 0;
}
