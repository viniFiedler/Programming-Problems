// https://codeforces.com/problemset/problem/834/A
#include <bits/stdc++.h>
using namespace std;
// passos:
// encontrar a posição de começo
// encontrar a posição de fim
// calcular o módulo do fim + distancia e inicio + distancia
// fim +

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char Cinicio, Cfim;
    int inicio, fim;
    int dist;
    int resultado;

    cin >> Cinicio >> Cfim;
    cin >> dist;

    /*
    O switch é fácil de vizualizar, mas pode-se
    usar com o resto do valor da tabela ascii ou qualquer outra forma,
    já que qualquer solução razoável não impactará significativamente na performace
     */

    switch (Cinicio)
    {
    case '<':
        inicio = 0;
        break;
    case '^':
        inicio = 1;
        break;
    case '>':
        inicio = 2;
        break;
    case 'v':
        inicio = 3;
        break;
    }

    switch (Cfim)
    {
    case '<':
        fim = 0;
        break;
    case '^':
        fim = 1;
        break;
    case '>':
        fim = 2;
        break;
    case 'v':
        fim = 3;
        break;
    }

    // considerando essas direções, podemos resolver esse problema facilmente
    // utilizando distâncias, similar a um circulo, se o inicio + a distância total
    // é igual ao fim então pode-se girar igual ao relógio
    // se fim + a distância = inicio então pode-se girar  contra o relógio
    // é importante lembrar ques estamos lidando com um círculo portanto nosso resultado só varia de [começo,fim]
    // e que é garantido que haja um resultado

    if ((inicio + dist) % 4 != fim)
    {
        // então, se for diferente do fim é counter-clockwise
        cout << "ccw\n";
    }

    else if ((fim + dist) % 4 == inicio)
    {
        // se for igual ao inicio então é ambos
        cout << "undefined\n";
    }

    else
        cout << "cw\n";
    return 0;
}
