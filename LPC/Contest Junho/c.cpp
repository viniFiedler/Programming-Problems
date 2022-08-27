#include <bits/stdc++.h>
using namespace std;

vector<int> V;

int main()
{
    int n, k, d;
    int cont = 0;
    cin >> n >> k >> d;
    for (int i = 0; i < k; i++)
    {
        V.push_back(i + 1);
    }
    bool Confirm = false;
    for (int i = 0; i < V.size(); i++)
    {
        int soma = n;
        while (soma > 0)
        {
            if (soma - V[i] >= 0 && V[i] >= d)
            {
                soma -= V[i];
            }
            if (soma - V[i] >= 0 && V[i] < d)
            {
                soma -= V[i];
            }
            if (soma - V[i] < d)
            {
                for (int j = 0; j < V.size(); j++)
                {
                    if (V[j] >= d && Confirm == false)
                    {
                        soma -= V[j];
                        Confirm = true;
                    }
                    else if (soma - V[j] > 0)
                    {
                        soma -= V[j];
                    }
                    if (soma == 0)
                    {
                        Confirm = true;
                        break;
                    }
                    else if (soma < 0)
                    {
                        break;
                    }
                }
            }
            if (soma == 0)
            {
                Confirm = true;
            }
        }
        if (Confirm == true && soma == 0)
        {
            cont++;
            Confirm = false;
        }
    }
    cout << cont << "\n";
}