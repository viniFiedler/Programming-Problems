#include <bits/stdc++.h>
using namespace std;

#define INF 2147483647
#define MAX_V 101
#define MAX_A 10001

typedef struct
{
    int v;    // vértice
    double w; // peso
} TAdj;

TAdj adj[MAX_V][MAX_A];
int grau[MAX_V]; // número de arestas no vértice
int d[MAX_V];    // distância
int p[MAX_V];    // pai do vertice
int visited[MAX_V];

void aresta(int a, int b, double w)
{
    adj[a][grau[a]].v = b;
    adj[a][grau[a]].w = w;
    grau[a]++;
}

bool bellmanFord(int inicial, int n)
{
    memset(p, -1, sizeof(p));
    for (int i = 0; i < n; i++)
        d[i] = INF;
    d[inicial] = 0;
    for (int i = 0; i < n - 1; i++)
    { //|V|-1 passos
        for (int j = 0; j < n; j++)
        { // para todas as
            if (d[j] == INF)
                continue;
            for (int k = 0; k < grau[j]; k++)
            { // arestas (j, k)
                if (d[j] + adj[j][k].w < d[adj[j][k].v])
                {
                    d[adj[j][k].v] = d[j] + adj[j][k].w;
                    p[adj[j][k].v] = j;
                }
            }
        }
    }
    // Verificando se há ciclo negativo
    for (int i = 0; i < n; i++)
    {
        if (d[i] == INF)
            continue;
        for (int j = 0; j < grau[i]; j++)
        {
            if (d[adj[i][j].v] > d[i] + adj[i][j].w)
                return false;
        }
    }
    return true;
}

int main()
{

    memset(grau, 0, sizeof(grau));
    memset(visited, 0, sizeof(visited));
    memset(p, -1, sizeof(p));

    int n, m;

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y, peso;
        cin >> x >> y >> peso;
        // printf("%d: %d\n", i, peso);
        aresta(x, y, peso);
    }

    bellmanFord(1, m);

    for (int i = 1; i <= n; i++)
    {
        d[i] != INF ? printf("%d ", d[i]) : printf("%d ", 30000);
    }
    printf("\n");
}