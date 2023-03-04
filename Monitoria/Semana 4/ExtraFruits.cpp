// https://open.kattis.com/problems/fruitbaskets
#include <bits/stdc++.h>
using namespace std;
// Vinicius Garcia
/*
    Problema:
        Calcular para a combinatória de n quais combinações são maiores que 200

    Resolução:
        A sua primeira aproximação provavelmente foi a de tentar calcular todas as possibilidades,
        e como deve ter percebido isso estourou tempo e por muito. Isso acontece pelo algoritmo
        da combinatória ser O(n!), portanto em casos com n = 25 já haverá time limit, muito mais
        em 40.

        Muito bem, mas e aí? Bom, esse é o tipo de exercício que se você for codar sem colocar nada
        em um papel antes você vai sair chorando do pq não deu certo. Concorda que o enunciado diz que
        todas as frutas possuem no minimo 50 gramas? Então podemos afirmar com 100% de certeza que em
        TODOS os casos quando houverem 4 ou mais frutas essa soma vai ser válida?

        aham... mas e dai? Bom, e se somássemos todas possibilidades e depois retirarmos as que não são válidas?
        isso reduziria drasticamente o número de operações realizads, já que só precisamos nos preucupar com casos
        em que temos a soma de 3 ou menos frutas.

        Mas antes precisamos achar a somatória total, para isso mostrarei com um exemplo

        para as frutas (n = 4), o prório exercicio afirma que o número de possibilidades = 2**n - 1

        50 60 70 120

        50 / 50 60 / 50 70 / 50 120 / 50 60 70 / 50 60 120 / 50 70 120 / 50 60 70 120
        60 / 60 70 / 60 120 /60 70 120
        70 / 70 120/
        120

        note que cada número aparece (2**(4 - 1)) = 8 vezes
        então podemos calcular (50 + 60 + 70 + 120) * 8 e obteremos a somatória das combinações.

        Logo, podemos fazer agora um algoritmo que verique as possiblidades restantes e as subtrai da soma total,
        obtendo assim o resultado da soma.

        Nosso Algoritmo vai rodar em O(n³) mas como nossa entrada só vai até 40, não teremos problemas quanto ao tempo.

        Fim :)


*/
int main()
{
    long long int soma = 0;
    int frutas[40];
    int num;

    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cin >> frutas[i];
        soma += frutas[i];
    }

    soma *= pow(2, num - 1);

    for (int i = 0; i < num; i++)
    {
        if (frutas[i] < 200)
            soma -= frutas[i];

        for (int j = i + 1; j < num; j++)
        {
            if (frutas[i] + frutas[j] < 200)
                soma -= frutas[i] + frutas[j];

            for (int k = j + 1; k < num; k++)
            {
                if (frutas[i] + frutas[j] + frutas[k] < 200)
                    soma -= frutas[i] + frutas[j] + frutas[k];
            }
        }
    }

    cout << soma << endl;
    return 0;
}