#include <stdio.h>
#include <stdlib.h>
#define max 501
#define NUMEGRANDE 1000000

int Grafo_Original[max][max], Grafo_Floyd[max][max], Vetor_Passou[max], Custo, Flag;

void Limpa_DFS()
{
    for (int i = 0; i < max; i++)
    {
        Vetor_Passou[i] = 0;
    }
    Custo = 0;
    Flag = 0;
}
void Limpa_Grafo()
{
    int i, j;
    for (i = 0; i < max; i++)
    {
        for (j = 0; j < max; j++)
        {
            if (i == j)
            {
                Grafo_Original[i][j] = 0;
                Grafo_Floyd[i][j] = 0;
            }
            else
            {
                Grafo_Original[i][j] = NUMEGRANDE;
                Grafo_Floyd[i][j] = NUMEGRANDE;
            }
        }
    }
}

void Insere(int No_01, int No_02, int Peso)
{
    Grafo_Original[No_01][No_02] = Peso;
    Grafo_Floyd[No_01][No_02] = Peso;
}

void Mostra_Original(int Vertices)
{
    int i, j;
    for (i = 1; i <= Vertices; i++)
    {
        for (j = 1; j <= Vertices; j++)
        {
            printf("%10d ", Grafo_Original[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

void Mostra_Floyd(int Vertices)
{
    int i, j;
    for (i = 1; i <= Vertices; i++)
    {
        for (j = 1; j <= Vertices; j++)
        {
            printf("%10d ", Grafo_Floyd[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

void Floyd_Warshall(int Maior_No)
{
    int i, j, k;
    for (k = 1; k <= Maior_No; k++)
    {
        for (i = 1; i <= Maior_No; i++)
        {
            for (j = 1; j <= Maior_No; j++)
            {
                Grafo_Floyd[i][j] = min(Grafo_Floyd[i][j], Grafo_Floyd[i][k] + Grafo_Floyd[k][j]);
            }
        }
    }
}

void Verifica_Custo(int Vertices)
{
    int i, j;
    for (i = 0; i <= Vertices; i++)
        for (j = 0; j <= Vertices; j++)
        {
            if (Grafo_Floyd[i][j] != NUMEGRANDE)
            {
                if (Grafo_Floyd[j][i] != NUMEGRANDE)
                {
                    Grafo_Original[i][j] = 0;
                    Grafo_Original[j][i] = 0;
                }
            }
        }
}

void DFS(int No_Inicial, int No_Final, int Vertices)
{
    int i;
    // linha de baixo eh um problematic
    Vetor_Passou[No_Inicial] = 1;
    if ((No_Inicial == No_Final) || (Flag == 1))
    {
        Flag = 1;
        return;
    }
    for (i = 1; i <= Vertices; i++)
    {
        if (Grafo_Original[No_Inicial][i] < NUMEGRANDE)
        {
            if (Vetor_Passou[i] == 0)
            {
                if (Flag == 1)
                    return;
                Custo += Grafo_Original[No_Inicial][i];
                DFS(i, No_Final, Vertices);
            }
        }
    }
}

int main()
{
    int Vertices, Arestas, Origem, Destino, Peso, Consultas;
    int i, j;
    scanf("%d %d", &Vertices, &Arestas);
    while (Vertices != 0 || Arestas != 0)
    {
        Limpa_Grafo();
        for (i = 0; i < Arestas; i++)
        {
            scanf("%d %d %d", &Origem, &Destino, &Peso);
            Insere(Origem, Destino, Peso);
        }
        scanf("%d", &Consultas);
        // Mostra_Original(Vertices);
        Floyd_Warshall(Vertices);
        // Mostra_Floyd(Vertices);
        Verifica_Custo(Vertices);
        // Mostra_Original(Vertices);
        for (i = 0; i < Consultas; i++)
        {
            scanf("%d %d", &Origem, &Destino);
            Limpa_DFS();
            DFS(Origem, Destino, Vertices);
            // linha de baixo problematica
            if (Vetor_Passou[Destino] == 0)
                printf("Nao e possivel entregar a carta\n");
            else
                printf("%d\n", Custo);
        }
        printf("\n");

        scanf("%d %d", &Vertices, &Arestas);

        // Mostra_Floyd(Vertices);
    }

    return 0;
}