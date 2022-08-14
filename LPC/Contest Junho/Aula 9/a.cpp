/*Check if a given graph is a tree */

#include <bits/stdc++.h>
using namespace std;
#define MAX_V 10001
#define MAX_A 20001

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
    visitado[s]++;
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

    initDfs();

    int n, m;
    int u, v;
    cin >> n >> m;
    initGrafo(n);
    if (m == n - 1)
    {
        bool sai = false;
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;
            aresta(u, v);
        }
        dfs(u);
        for (int i = 1; i <= n && !sai; i++)
        {
            if (visitado[i] != 1)
            {
                sai = true;
            }
        }

        sai ? printf("NO\n") : printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}