#include <stdio.h>
#include <stdlib.h>
int visitados[49] = {0};
int adj[49][49] = {0};
int cont = 0;
int tam = 49;

int tam;

void fazVertice(int no1, int no2)
{
    adj[no1][no2] = 1;
    adj[no2][no1] = 1;
}

void dfs(int no)
{
    visitados[no] = 1;
    for (int i = 0; i < tam; i++)
    {

        if (adj[no][i])
        {
            if (!visitados[i])
            {
                cont++;
                dfs(i);
                cont++;
            }
        }
    }
}

void limpaVetor()
{
    cont = 0;
    for (int i = 0; i < 50; i++)
    {
        visitados[i] = 0;
        for (int j = 0; j < 50; j++)
        {
            adj[i][j] = 0;
        }
    }
}
int main()
{
    int testes;
    scanf("%d", &testes);

    while (testes--)
    {
        limpaVetor();
        int comeco;
        scanf("%d", &comeco);
        int vertices, arestas;
        scanf("%d %d", &vertices, &arestas);
        for (int i = 0; i < arestas; i++)
        {
            int no1, no2;
            scanf("%d %d", &no1, &no2);
            fazVertice(no1, no2);
        }

        dfs(comeco);
        printf("%d\n", cont);

        // for (int i = 0; i < tam; i++)
        // {
        //     printf("%d:", i);
        //     for (int j = 0; j < tam; j++)
        //         if (adj[i][j])
        //         {
        //             printf(" %2.0d", j);
        //         }
        //     printf("\n");
        // }
    }

    return 0;
}