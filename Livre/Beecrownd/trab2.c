#include <stdio.h>
#include <stdlib.h>
#define max 502
#define INF 1000000

int Grafo[max][max];

void Limpa_Grafo()
{
    int i, j;
    for (i = 1; i < max; i++)
    {
        for (j = 1; j < max; j++)
        {
            Grafo[i][j] = INF;
        }
    }
}

void Insere(int Origem, int Destino, int Peso)
{
    Grafo[Origem][Destino] = Peso;
    if (Grafo[Destino][Origem] != INF)
    {
        Grafo[Origem][Destino] = 0;
        Grafo[Destino][Origem] = 0;
    }
}

int Dijkstra(int Origem, int Destino, int Numero_Vertices)
{
    int Minimo, Vertice_Atual;
    int Passou[max], Custo[max];
    int i;
    for (i = 1; i <= Numero_Vertices; i++)
    {
        Passou[i] = 0;
        Custo[i] = INF;
    }
    Custo[Origem] = 0;
    Vertice_Atual = Origem;

    while (Vertice_Atual != Destino)
    {
        for (i = 1; i <= Numero_Vertices; i++)
        {
            if (Custo[Vertice_Atual] + Grafo[Vertice_Atual][i] < Custo[i])
            {
                Custo[i] = Custo[Vertice_Atual] + Grafo[Vertice_Atual][i];
            }
        }
        Minimo = INF;
        Passou[Vertice_Atual] = 1;
        for (i = 1; i <= Numero_Vertices; i++)
        {
            if ((Custo[i] < Minimo) && (Passou[i] != 1))
            {
                Minimo = Custo[i];
                Vertice_Atual = i;
            }
        }
        if (Minimo == INF)
        {
            return INF;
        }
    }
    return Custo[Destino];
}

int main()
{
    int Vertices, Arestas, Casos, Origem, Destino, Peso, Resultado;
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
        scanf("%d", &Casos);
        for (i = 0; i < Casos; i++)
        {
            scanf("%d %d", &Origem, &Destino);
            Resultado = Dijkstra(Origem, Destino, Vertices);
            if (Resultado != INF)
            {
                printf("%d\n", Resultado);
            }
            else
            {
                printf("Nao e possivel entregar a carta\n");
            }
        }
        scanf("%d %d", &Vertices, &Arestas);
        printf("\n");
    }
    return 0;
}
