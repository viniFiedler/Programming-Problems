#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, n, cont, soma;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> n;
        int R_n = (int)sqrt(n);
        for (int j = R_n; j >= 1; j--)
        {
            cont = 0;
            soma = 0;
            int pot = pow(j, 2);
            if (n % pot == 0)
            {
                while (soma < n)
                {
                    soma += pot;
                    cont++;
                }
                if (soma == n)
                {
                    cout << cont << "\n";
                    break;
                }
            }
        }
    }
    return 0;
}