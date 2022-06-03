// Cumulative Sum Query

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;

    cin >> N;
    vector<int> vetor;
    int n;
    for (int i = 0; i < N; i++)
    {
        cin >> n;
        vetor.push_back(n);
    }

    vector<int> somas;

    int soma = 0;

    for (int i = 0; i < N; i++)
    {
        soma += vetor[i];
        somas.push_back(soma);
    }
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int come, fim;
        cin >> come >> fim;
        if (come == 0)
        {
            cout << somas[fim] << "\n";
            continue;
        }
        cout << somas[fim] - somas[come - 1] << "\n";
    }
    return 0;
}