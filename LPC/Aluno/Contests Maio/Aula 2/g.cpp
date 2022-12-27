#include <bits/stdc++.h>

using namespace std;
typedef struct
{
    int time;
    int direcao;

} Pessoa;

int main()
{
    int numPessoas;
    vector<Pessoa> pessoas;
    cin >> numPessoas;
    int i = 0;
    while (i < numPessoas)
    {
        Pessoa entra;

        cin >> entra.time;
        cin >> entra.direcao;

        pessoas.push_back(entra);
        i++;
    }

    // pegar todos os tempos <= a ao tempo da ultima Pessoa que entrou naquela direção + 10
    int tempo = 0;

    while (!pessoas.empty())
    {
        int lado;
        lado = pessoas[0].direcao;

        int j = 1;
        for (i = 0; i < pessoas.size() - 1; i++)
        {
            if (pessoas[i].time <= pessoas[j].time + 10 && pessoas[i].direcao == pessoas[j].direcao)
            {
                tempo = pessoas[j].time + 10;
                printf("tchau %d %d tempo %d\n", pessoas[i].time, pessoas[i].direcao, pessoas[i].time);

                // exclui o primeiro elemento
                pessoas.erase(pessoas.begin() + i);
                j = i;

                // soma o tempo
            }
        }
    }

    cout << tempo << endl;
    // fazer a deleção de todos elas da lista de Pessoas
    // somar o tempo da ultima Pessoa em 10 e fazer a mesma verificação
    // se não tiver ninguem mais para ir naquela direção, verificar o horario da proxima e começar toda a verificação denovo

    return 0;
}