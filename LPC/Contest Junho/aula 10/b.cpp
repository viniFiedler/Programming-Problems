// Roads of NITT
#include <bits/stdc++.h>
using namespace std;

#define MAX_N 20000
int pai[MAX_N + 1];

void init()
{
    for (int i = 1; i <= MAX_N; i++)
        pai[i] = i;
}

int find(int x)
{
    if (pai[x] == x)
        return x;
    return find(pai[x]);
}

bool same(int x, int y)
{
    return find(x) == find(y);
}

void merge(int u, int v)
{
    int a = find(u);
    int b = find(v);
    pai[a] = b;
}
int main()
{

    int testes;
    cin >> testes;

    while (testes--)
    {
        init();

        map<int, pair<int, int>> arestas;
        int hostels;
        int camelo;
        cin >> hostels;
        for (int i = 1; i < hostels; i++)
        {
            int x, y;
            cin >> x >> y;
            arestas[i] = {x, y};
        }
        int numQueries;

        vector<pair<char, int>> queries;

        cin >> numQueries;
        for (int i = 0; i < numQueries; i++)
        {
            char c;
            cin >> c;
            if (c == 'Q')
                queries.emplace_back(c, 0);
            else
            {
                int a;
                cin >> a;
                queries.emplace_back(c, a);
                arestas[a] = {-arestas[a].first, arestas[a].second};
            }
        }

        for (int i = 1; i < hostels; i++)
        {
            int x = arestas[i].first, y = arestas[i].second;
            if (x > 0)
            {
                merge(x, y);
                merge(y, x);
            }
        }
        stack<int> valores;
        for (int i = 0; i < numQueries; i++)
        {
            char op = queries[i].first;
            int val = queries[i].second;

            if (op == 'R')
            {
                merge(-arestas[val].first, arestas[val].second);
                merge(arestas[val].second, -arestas[val].first);
                printf("o numero %d pertece ao %d ", -arestas[val].first, find(-arestas[val].first));
                printf("o numero %d pertece ao %d \n", arestas[val].second, pai[arestas[val].second]);
            }
            else if (op == 'Q')
            {
                set<int> aux;
                for (int j = 1; j <= hostels; j++)
                {
                    aux.insert(find(j));
                    // printf("%d %d \n", j, pai[j]);
                }
                aux.size() == 1 ? valores.push(0) : valores.push(aux.size());
            }
        }

        for (; valores.size() > 0;)
        {
            cout << valores.top() << endl;
            valores.pop();
        }
        cout << endl;
    }
}