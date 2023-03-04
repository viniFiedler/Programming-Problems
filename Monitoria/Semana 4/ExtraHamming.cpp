// https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=670
#include <bits/stdc++.h>
using namespace std;
/*
Problema: Dado o número de bits, achar a quantidade de bits setados em diversas sequências de bits

Resolução:
    Primeiro é necessário saber operações bitwise, procure na internet para saber
    o que o operdador >> faz, mas se você já viu alguma coisa de bits deve ter noção
    do que é right shift.

    Segundo, a operação _builtin_popcount(bit) aqui há várias formas de resolver o problema
    de quantos bits estão setados, poderia ser por loop fazendo módulo de 2 ou por iteração
    em um array de bits, mas optei por essa função. Saber essa função não é obrigatório, durante
    um competição é mais provável que ela nem venha na mente.

    Terceiro, Imprimir o bits também pode ser feito de diversas formas, optei por essa já que
    poderia imprimir iterativamente, sem problemas de colocar nada em pilhas ouj coisa parecida.

Nota

    Apesar do texto falar que são "muitas operações", só haverão 2¹⁶ operações, no máximo.




*/
int main()
{
    int teste;

    cin >> teste;

    while (teste--)
    {
        int bit = 0;
        int tamanho;
        int dist;
        cin >> tamanho >> dist;
        int aux = 1, cont;
        cont = pow(2, tamanho);
        for (int i = 0; i < tamanho; i++)
        {
            aux = (aux << 1);
        }

        while (cont--)
        {
            if (__builtin_popcount(bit) == dist)
            {

                int auxb = (aux >> 1);
                while (auxb)
                {
                    int sai = (auxb & bit) ? 1 : 0;
                    cout << sai;
                    auxb = (auxb >> 1);
                }
                cout << "\n";
            }
            bit++;
        }

        if (teste != 0)
            cout << "\n";
    }

    return 0;
}