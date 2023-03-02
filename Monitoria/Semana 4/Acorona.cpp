// https://www.codechef.com/problems/COVID19?tab=statement
#include <bits/stdc++.h>
using namespace std;
int contador;

// para o back tracking
int vetor[11] = {0};
int passou[11] = {0};

// função recursiva que vai "Espalhar o virus"
// incia em um dado ponto e verifica se no vetor existe uma pessoa ali, se houver
// tenta espalhar para as pessoas adjacentes + 1
// porem se o vetor passou indicar que essa funcao ja passou la, ele retorna
// por isso foi usado backtracking e brute force

void espalha(int no)
{

    if (vetor[no] == 0 || no < 0 || no >= 11 || passou[no])
        return;

    contador++;
    passou[no] = 1;

    espalha(no + 1);
    espalha(no + 2);
    espalha(no - 1);
    espalha(no - 2);
}

int main()
{
    int testes;
    scanf("%d", &testes);
    while (testes--)
    {
        int n;
        int maior = 0;
        int menor = INT_MAX;
        memset(vetor, 0, sizeof(vetor));
        scanf("%d", &n);
        // pega as posicoes no vetor
        for (int i = 0; i < n; i++)
        {
            int x;
            scanf("%d", &x);
            vetor[x] = 1;
        }

        for (int i = 0; i < 11; i++)
        {
            // para cada lugar que houver uma pessoa

            if (vetor[i] != 0)
            {
                // espalha o virus para aquela situacao
                espalha(i);

                // avalia a situacao
                if (contador > maior)
                    maior = contador;

                if (contador < menor)
                    menor = contador;
            }
            contador = 0;
            memset(passou, 0, sizeof(passou));
        }
        printf("%d %d\n", menor, maior);
    }
    return 0;
}
