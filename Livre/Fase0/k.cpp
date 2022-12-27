#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, v;
    cin >> n >> v;
    int melhorVolta = INT_MAX;
    int melhorPiloto = 0;
    int posVetor;
    vector<vector<int>> m;
    for (int k = 0; k < n; k++)
    {
        vector<int> aux;
        string a;
        int numPiloto;
        cin >> numPiloto;

        aux.push_back(numPiloto);

        for (int i = 0; i < v; i++)
        {
            int a = 0, b = 0, c = 0;
            scanf("%d:%d:%d", &a, &b, &c);
            int d = c;
            c += a * 1000 * 60;
            c += b * 1000;

            if (c < melhorVolta)
            {
                cout << a << ":" << b << ":" << d << '\n';
                melhorVolta = c;
                melhorPiloto = numPiloto;
                posVetor = k;
            }
            aux.push_back(c);
        }
        m.push_back(aux);
    }

    for (int i = 0; i < n; i++)
    {
        cout << m[i][0] << endl;
        for (int j = 1; j < v + 1; j++)
        {
            cout << m[i][j] << endl;
            if (melhorVolta > m[i][j])
            {

                melhorVolta = m[i][j];
                melhorPiloto = m[i][0];
                posVetor = i;
            }
            else if (melhorVolta == m[i][j])
            {
                // cout << i << endl;
                // cout << posVetor << endl;
                // cout << m[i][2] << endl;
                // cout << m[posVetor][2] << endl;

                if (m[i][1] > m[posVetor][1])
                {
                    cout << m[i][1] << endl;
                    cout << m[i][0] << endl;
                    melhorPiloto = m[i][0];
                    posVetor = i;
                }
            }
        }
    }

    if (melhorPiloto == 0)
        cout << "NENHUM\n";
    else
        cout << melhorPiloto << "\n";
    return 0;
}