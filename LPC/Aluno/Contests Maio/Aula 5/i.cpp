
// Defense of a Kingdom

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int repete;
    cin >> repete;
    while (repete--)
    {
        int xMax, yMax, numberCrossBow;
        cin >> xMax >> yMax >> numberCrossBow;
        int tabuleiro[yMax][xMax];
        int maior = 0;
        // o tabuleiro vai ser em uma vez mais que o comum para evitar erros de memoria

        for (int i = 0; i < yMax + 1; i++)
            for (int j = 0; j < xMax + 1; j++)
                tabuleiro[i][j] = 0;

        for (int i = 0; i < numberCrossBow; i++)
        {
            int x, y;

            cin >> x >> y;
            x--;
            y--;
            for (int j = 0; j < yMax; j++)
            {
                tabuleiro[j][x] = 1;
            }
            for (int j = 0; j < xMax; j++)
            {
                tabuleiro[y][j] = 1;
            }
        }
        /*
        for (int i = 0; i < yMax + 1; i++)
        {
            for (int j = 0; j < xMax + 1; j++)
                printf(" %d ", tabuleiro[i][j]);
            printf("\n");
        }
        */

        for (int i = 0; i < yMax; i++)
        {
            for (int j = 0; j < xMax; j++)
            {
                if (tabuleiro[i][j] == 0)
                {

                    int y = i, x = j + 1;
                    int lastx, lasty;
                    int lateral = 0;
                    int base = 1;
                    while (y < yMax && !tabuleiro[y][j])
                    {
                        tabuleiro[y][j]++;
                        lasty = y;
                        y++;
                        lateral++;
                    }

                    while (x < xMax && !tabuleiro[i][x])
                    {

                        tabuleiro[i][x]++;
                        lastx = x;
                        x++;
                        base++;
                    }

                    for (int m = y; m < lasty; m++)
                    {
                        for (int n = x; n < lastx; n++)
                        {
                            tabuleiro[m][n] = 1;
                        }
                    }

                    if (tabuleiro[lasty + 1][lastx + 1] == 1)
                    {
                        maior = max(maior, lateral * base);
                    }
                }
            }
        }

        printf("%d\n", maior);
    }
    return 0;
}