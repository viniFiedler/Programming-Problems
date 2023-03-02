// https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1113
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
/*
Exercicio:
    Basicamenta há uma lista circular de filas de inteiros
    cada inteiro representa uma posição da lista circular,
    seu objetivo é calcular o tempo (baseado no número de operações)
    que é gasto para esvaziar todas as filas.

Resolução
    Se você (AKA pilha) conseguir colocar um inteiro n na
    posição n da lista então parabéns, uma carga a menos
    agora continue rodando a lista até você ter esvaziado todas as
    filas.

    No geral, o texto é longo mas a implementação não é tão díficil
    usando o c++.

 */

int main()
{
    int SET;
    cin >> SET;

    while (SET--)
    {
        int n, s, q;
        cin >> n >> s >> q;
        queue<int> filas[101];

        for (int i = 1; i <= n; i++)
        {
            int temp, num;
            cin >> temp;
            for (int j = 0; j < temp; j++)
            {
                cin >> num;
                filas[i].push(num);
            }
        }

        int tempo = 0;
        stack<int> voce;
        for (int i = 1;; i++)
        {
            if (i > n)
                i = 1;

            while (!voce.empty() && (voce.top() == i || filas[i].size() < q))
            {
                // esse segundo voce.empty eh necessario uma vez que se a pilha nao possuir
                // um topo, e houver a chama voce.top() ela retornará um erro
                if (voce.top() != i)
                {
                    int num = voce.top();
                    filas[i].push(num);
                }

                voce.pop();
                tempo++;
            }

            while ((voce.size() < s) && !filas[i].empty())
            {
                int temp = filas[i].front();
                voce.push(temp);
                filas[i].pop();
                tempo++;
            }

            int fim = 1;

            for (int i = 1; i <= n; i++)
            {
                if (!filas[i].empty())
                {
                    fim = 0;
                }
            }

            if (fim && voce.empty())
                break;

            tempo += 2;
        }
        cout << tempo << "\n";
    }

    return 0;
}