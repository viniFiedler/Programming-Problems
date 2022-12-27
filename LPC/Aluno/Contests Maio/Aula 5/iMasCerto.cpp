// o objetivo e pegar uma lista de torre
// depois para cada torre achar a torre com maior distancia possivel ( euclidiana )
// se houver alguma interrupcao de torres ( considero uma torre a coluna a linha que ela ocupa)
// entao ela passa para a segunda torre mais distante
// e continua assim ate achar uma torre sem interrupcao
// se ela achar duas ou mais torres na mesma distancia vai procurar pela que nao possui interrupcao

// nota, o algoritimo nao vai andar na diagonal uma vez que nao estou procurando quadrados,
// ele precisa andar verticalmente e horizontalmente

#include <bits/stdc++.h>
using namespace std;
typedef struct torres
{
    int x, y;
};

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
    }
}