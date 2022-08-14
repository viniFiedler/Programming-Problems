/*Check whether the given undirected graph is connected. That its possible to go from any vertex to any other along the edges of this graph.*/

#include <bits/stdc++.h>
using namespace std;
#define MAX_V 100
typedef struct
{
    int v; // vértice adjacente
} TAdj;

vector<TAdj> adj[MAX_V]; // Lista de adjacência

int grau[MAX_V];
// número de arestas do vértice
void initGrafo(int qtdeVertices)
{
    memset(grau, 0, sizeof(grau));
    for (int i = 0; i < qtdeVertices; i++)
        adj[i].clear();
}

// Cria aresta de a para b, com peso w
void aresta(int a, int b)
{
    TAdj aux;
    aux.v = b;
    grau[a]++;
    adj[a].push_back(aux);

    aux.v = a;
    grau[b]++;
    adj[b].push_back(aux);

    // Se o grafo for não orientado, também adicionamos a aresta (b, a) com
}

int visitado[MAX_V];
int p[MAX_V];
int ordemVis;

void initDfs()
{
    memset(visitado, 0, sizeof(visitado));
    memset(p, -1, sizeof(p));
    ordemVis = 0;
}

void dfs(int s)
{
    visitado[s] = ++ordemVis;
    for (auto t : adj[s])
    {
        if (visitado[t.v] == 0)
        {
            p[t.v] = s;
            dfs(t.v);
        }
    }
}

int main()
{
    int n, m;
    initDfs();
    cin >> n >> m;
    initGrafo(n);
    int u, v;

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        aresta(u, v);
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     printf("%d ", grau[i]);
    // }
    // printf("\n");
    dfs(u);
    bool foi = true;
    for (int i = 1; i <= n && foi; i++)
    {
        if (visitado[i] == 0)
            foi = false;
        // printf("%d %d %d\n", i, p[i], visitado[i]);
    }

    foi ? printf("YES\n") : printf("NO\n");

    return 0;
}