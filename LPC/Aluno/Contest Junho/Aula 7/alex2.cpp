#include <bits/stdc++.h>
using namespace std;

vector<int> Tam;

void Corta(int TT)
{
    int n = Tam.size();
    int pd[TT + 1];
    for (int i = 1; i <= TT; i++)
    {
        pd[i] = 0;
    }
    pd[0] = TT;
    for (int i = 1; i <= TT; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j <= i)
            {
                pd[i] = max(pd[i], pd[i - j] - Tam[j]);
            }
            else
            {
                pd[i] = max(pd[i], pd[0] - Tam[j]);
            }
        }
    }
    for (int i = 0; i <= TT; i++)
    {
        cout << pd[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int T, TT;
    cin >> TT;
    for (int i = 0; i < 3; i++)
    {
        cin >> T;
        Tam.push_back(T);
    }
    Corta(TT);
}