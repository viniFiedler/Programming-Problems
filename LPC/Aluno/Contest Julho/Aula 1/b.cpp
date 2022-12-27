#include <bits/stdc++.h>
using namespace std;
#define MAX 1000001
int a[MAX], n, m;
char S[MAX], P[MAX];

void calculatePrefix()
{
    int
        i = 0,
        j = -1;
    a
        [0] = -1;
    while (i < m)
    {
        while (j >= 0 && P[i] != P[j])
            j = a[j];
        i++;
        j++;
        a[i] = j;
    }
}
vector<int> KMP2()
{ // retorna todas as ocorrências da substring
    vector<int> resp;
    int i = 0, j = 0;
    calculatePrefix();
    while (i < n)
    {
        while (j >= 0 && S[i] != P[j])
            j = a[j];
        i++;
        j++;
        if (j == m)
        {
            resp.push_back(i - m);
            j = a[j];
        }
    }
    return resp;
}

int main()
{
    int teste;
    cin >> teste;

    while (teste--)
    {
        cin >> S;
        cin >> P;
        n = strlen(S);
        m = strlen(P);
        vector<int> locais = KMP2();

        if (locais.size() == 0)
        {
            cout << "\nNot Found\n";
        }
        else
        {
            cout << locais.size() << endl;

            for (int i = 0; i < locais.size(); i++)
            {
                cout << locais[i] + 1 << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}