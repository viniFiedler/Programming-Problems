#include <bits/stdc++.h>
using namespace std;
int jogada[10000001];

int main()
{
    memset(jogada, 0, sizeof(jogada));
    jogada[0] = 1;

    int entrada;
    cin >> entrada;

    for (int i = 1; i <= entrada; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (i - j >= 0)
                jogada[i] = (jogada[i] + jogada[i - j]) % (1000000000 + 7);
        }
    }
    cout << jogada[entrada] << endl;

    return 0;
}