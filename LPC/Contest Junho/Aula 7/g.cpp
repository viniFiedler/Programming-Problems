#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, t;
    while (cin >> m >> n >> t)
    {
        int i, j;
        int maior = INT_MIN;
        int cerveja = INT_MAX;

        for (i = 0; i * n <= t; i++)
        {

            for (j = 0; j * m + i * n <= t; j++)
            {
                if (j * m + i * n <= t)
                {

                    if (cerveja > t - (i * n + j * m))
                    {
                        maior = j + i;
                        cerveja = t - (i * n + j * m);
                    }
                    else if (cerveja == t - (i * n + j * m))
                    {
                        maior = max(j + i, maior);
                    }
                }
            }
        }

        printf("%d", maior);
        if (cerveja)
            printf(" %d", cerveja);
        printf("\n");
    }
    return 0;
}