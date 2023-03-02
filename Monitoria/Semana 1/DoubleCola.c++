// https://codeforces.com/problemset/problem/82/A
#include <bits/stdc++.h>
using namespace std;
/*
Sheldons voltam para o começo da fila a cada 5.2^n latas
sendo n = o número de vezes que eles apareceram no começo
n[0,infinito]

portanto pordemos afirmar que o número da lata que o último Howard beber
se dá pela somatória de 5.2^n n = 0

Logo, quando uma entrada K é inserida, podemos afirmar que este valor está entre
5.2^n e (5.2^n + 5.2^(n+1))

e que 2^(n+1) representa a quantidade de cada pessoa naquele intervalo

portanto a pessoa que estiver bebendo a lata K é referente a

pos = (K - somatória(n)) / 2^n+1 sendo pos o número da posição da pessoa na primeira fila

note que K sempre será > somatoria(n)

([0,1[ Sheldon, [1,2[] Leonard... [4,5]Howard)
Os Howards possuem intervalo fechado, já que quando K == 5.2^n, a pessoa a beber é SEMPRE o Howard.


Portante, o mais demorado da nossa busca é achar o n,
mas ele é encontrado no tempo de O(log(n))
nesse caso, no máximo 30 iterações
*/

int main()
{
    int K;
    string Pessoa;

    // a função POW() é custosa, o ideal seria utilizar operações bitwise para
    // achar potências de 2, mas nesse ponto do curso ainda não vimos, portanto
    // utlizarei um multiplicador (2^n), Para mais explicações segue o Link:
    // https://stackoverflow.com/questions/12556906/are-2n-exponent-calculations-really-less-efficient-than-bit-shifts
    int multiplicador = 1;
    int valor = 5;

    cin >> K;

    int resultado = K - 1;

    // se o K for menor que 5 não é necessário fazer nenhuma verificação
    if (K > 5)
    {
        for (int i = 1; i <= 30; i++)
        {
            if (K <= valor)
            {
                // se parou entao 5.2^n+1 maior que k (oq não deve acontecer, portanto devemos diminuir esse valor)
            }

            multiplicador *= 2;

            valor += (5 * multiplicador);
        }

        // voltar ao 5.2^n

        valor -= 5 * multiplicador;

        resultado = (int)(K - valor) / multiplicador;
    }

    switch (resultado)
    {
    case 0:
        Pessoa = "Sheldon";
        break;
    case 1:
        Pessoa = "Leonard";
        break;
    case 2:
        Pessoa = "Penny";
        break;
    case 3:
        Pessoa = "Rajesh";
        break;
    case 4:
    case 5:
        Pessoa = "Howard";
        break;
    }
    cout << Pessoa << "\n";
    return 0;
}