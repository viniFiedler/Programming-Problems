// https://open.kattis.com/problems/sim
#include <bits/stdc++.h>
#include <list>
using namespace std;
/*

Problema:
    Usar estrutura de dados para tirar tanto do meio
    quanto do final em um bigO razoável

Resolução:
    Primeiro tentei usando 2 pilhas, porém quando a entrada
    superava 10⁶ esse método falhava uma vez que no pior caso,
    a complexidade era O(n²).

    Então a próxima estrututra de dados é a lista (encadeada),
    e sua capacidade de retirar qualquer elemento do vetor.
    essa retirada se dá por O(n) como poder ser observado na tabela:
    https://github.com/gibsjose/cpp-cheat-sheet/blob/master/General/Data%20Structures.png
    Portanto, a maior dificuldade do Exercício reside em usar os ponteiros da lista

    É importante observar que tanto a função list.erase() quanto
    list.insert() retornam o endereço que o ponteiro aponta após
    a remoção, por isso, usando o ponteiro podemos obter onde foi
    feita essa mudança e assim adicionar um espaço de memória ou subtrair.


Sobre Ponteiros:
    Bom, dependendo de onde você está no curso de ciência da computação
    talvez saiba ou não como funcionam ponteiros em c++. Vou te dar uma pequena
    (realmente pequena) introdução.

    Um ponteiro é um espaço de memória que contem a a posição de outro espaço de memória
    em estrutras de dados simples há apenas um ponteiro que aponta para o começo da lista.
    Pode surgir na sua mente de como é feito o acesso em elementos subsquentes, a resposta é
    por soma. Por exemplo, 1 INT possui 4 bytes, se seu array de int começar na posição 0 da
    memória então o seu segundo elemento vai estar em 0 + 4 = 4 e o seu terceito vai estar em 4 + 4 =8
    e assim sucessivamente.

    Beleza, mas o qual a relação disso com o exercício? Bom, como podem ver, eu usei ++ e --
    (mover o ponteiro para tras e frente na estrutura) na manipulação de ponteiros e ainda
    que usando estruturas de dados mais complexa, isso só é possivel pq o c++ cuida disso por
    debaixo dos panos.

    Agora você tem o entendimento básico de como essa resolução funciona


*/

int main()
{
    int testes;
    scanf("%d\n", &testes);

    while (testes--)
    {
        list<char> lista;

        string letras;
        getline(cin, letras);
        int tamanho = letras.size();
        char letra;
        auto pos = lista.begin();
        for (int i = 0; i < tamanho; i++)
        {
            letra = letras[i];

            if (letra != '\n')
            {

                if (letra == '[')
                {
                    pos = lista.begin();
                }
                else if (letra == ']')
                {
                    pos = lista.end();
                }
                else if (letra == '<' && pos != lista.begin())
                {
                    if (lista.size() > 0)
                    {
                        pos = lista.erase(--pos);
                    }
                }
                else
                {
                    if (letra != '<')
                    {
                        pos = lista.insert(pos, letra);
                        pos++;
                    }
                }
            }
        }
        for (char it : lista)
            cout << it;
        cout << "\n";
    }

    return 0;
}