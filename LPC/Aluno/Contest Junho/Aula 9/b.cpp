// Find the Treasure

#include <bits/stdc++.h>
using namespace std;
#define MAX_V 100
#define MAX_A 10
int grau[MAX_V]; // número de arestas no vértice
int d[MAX_V];    // distância
int p[MAX_V];    // pai do vertice
int visited[MAX_V];

int adj[MAX_V][MAX_A];

void aresta(int a, int b)
{
    adj[a][grau[a]] = b;
    grau[a]++;

    adj[b][grau[b]] = a;
    grau[b]++;
}

void bfs(int inicio)
{
    int s, t;
    queue<int> Q;
    memset(visited, 0, sizeof(visited));
    memset(p, -1, sizeof(p));
    d[inicio] = 0;
    visited[inicio] = 1;
    Q.push(inicio);
    while (!Q.empty())
    {
        s = Q.front();
        Q.pop();
        for (int i = 0; i < grau[s]; i++)
        {
            t = adj[s][i];
            if (visited[t] == 0)
            {
                visited[t] = 1;
                d[t] = d[s] + 1;
                p[t] = s;
                Q.push(t);
            }
        }
    }
}

int main()
{
    int t;

    cin >> t;

    while (t--)
    {
        memset(grau, 0, sizeof(grau));
        memset(visited, 0, sizeof(visited));
        memset(p, -1, sizeof(p));

        int N;
        cin >> N;

        for (int i = 1; i <= N; i++)
        {
            int numPossiveis;
            cin >> numPossiveis;
            for (int j = 0; j < numPossiveis; j++)
            {
                int abre;
                cin >> abre;
                aresta(i, abre);
            }
        }

        bfs(N);

        if (d[1] > 0)
        {
            printf("%d\n\n", d[1]);
            int ant = 1;
            queue<int> listaLetras;
            listaLetras.push(1);
            for (int i = 1; i < N;)
            {
                printf("vendo %d\n", i);
                int auxI = i;
                for (int j = grau[i] - 1; j > 0; j--)
                {
                    // printf("  eh adj %d\n", adj[i][j]);
                    if (d[adj[i][j]] == d[i] - 1)
                    {
                        auxI = adj[i][j];
                        printf(" auxI %d\n", auxI);
                    }
                }
                i = auxI;
                if (auxI != N)
                    listaLetras.push(auxI);
            }
            while (listaLetras.size())
            {
                cout << listaLetras.front() << " ";
                listaLetras.pop();
            }
            cout << listaLetras.front() << endl
                 << endl;
        }
        else
        {
            printf("%d\n\n", -1);
        }
    }

    return 0;
}