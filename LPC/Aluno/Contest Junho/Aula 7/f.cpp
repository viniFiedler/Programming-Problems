//
#include <bits/stdc++.h>
using namespace std;

typedef struct tesouro
{
    int tempo = {1000000};
    int ouro = {-1000000};
} tesouro;

int main()
{
    int sai;
    string espaco = "a";
    do
    {
        sai = 1;
        int tempo, modificador;
        int tesouros;
        tesouro vet[30];
        int maior = 0;
        int posMaiorI, posMaiorJ;
        cin >> tempo >> modificador;
        cin >> tesouros;
        int grid[tempo + 1][tesouros];

        memset(grid, -1000000, sizeof(grid));

        for (int i = 0; i < tesouros; i++)
        {
            grid[0][i] = 0;
        }

        for (int i = 0; i < tesouros; i++)
        {
            tesouro aux;
            cin >> aux.tempo >> aux.ouro;
            aux.tempo = aux.tempo * modificador * 3;
            vet[i] = aux;
        }

        // acha o melhor caminho
        for (int i = 0; i < tempo; i++)
        {
            // laco for
            for (int j = 0; j < tesouros; j++)
            {
                // se i for menor que o valor daquele tesouro j passar para
                // a proxima iteracao
                if (i - vet[j].tempo < 0)
                    continue;

                // funcao se ele encontrar menor que zero
                for (int k = 0; k < tesouros; k++)
                {
                    grid[i][j] = max(grid[i][j], grid[i - vet[j].tempo][k]);
                }

                if (grid[i][j] >= 0)
                {
                    grid[i][j] += vet[j].ouro;
                    if (grid[i][j] > maior)
                    {
                        maior = grid[i][j];
                        posMaiorI = i;
                        posMaiorJ = j;
                    }
                }
            }
        }
        cout << maior << endl;

        // acha quais foram os valores do melhor caminho
        vector<tesouro> pegos;
        int i = posMaiorI;
        while (i > 0)
        {

            pegos.push_back(vet[posMaiorJ]);
            i -= vet[posMaiorJ].tempo;

            for (int j = 0; j < tesouros; j++)
            {
                int maior = 0;
                if (grid[i][j] > 0)
                {
                    posMaiorJ = j;
                }
            }
        }

        cout << pegos.size() << endl;
        for (i = 0; i < pegos.size(); i++)
        {
            cout << pegos[i].tempo / (modificador * 3) << " " << pegos[i].ouro << endl;
        }

        if (getline(cin, espaco))
        {
            printf("\n");
            sai++;
        }
        sai--;

    } while (sai);

    return 0;
}