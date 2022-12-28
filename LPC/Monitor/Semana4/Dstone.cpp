#include <bits/stdc++.h>
using namespace std;
// para cada pedra ela pode ir para direita ou para esquerda (2 movimentos)
// como ha vinte pedras entao 2^(20) == 1048576
// 1048576 < 10 ^ 9 portanto o bruteforce vai rodar em menos de 1 segundo com 20 pedras
int pedras[20] = {0};
int pesoMinimo = INT_MAX;
int n;

void contaPedra(int i, int pilhaA, int pilhaB)
{
    if (i == n)
    {
        pesoMinimo = min(abs(pilhaA - pilhaB), pesoMinimo);
        return;
    }

    contaPedra(i + 1, pilhaA + pedras[i], pilhaB);
    contaPedra(i + 1, pilhaA, pilhaB + pedras[i]);
}

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pedras[i]);
    }

    contaPedra(0, 0, 0);
    printf("%d\n", pesoMinimo);

    return 0;
}
