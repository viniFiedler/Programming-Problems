#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tamanhoVet, distanciaVet;
    cin >> tamanhoVet;
    cin >> distanciaVet;

    vector<int> vetor;
    list<int> maiores;
    int num;
    for (int i = 0; i < tamanhoVet; i++)
    {

        cin >> num;
        // cout << i << num << endl;
        vetor.push_back(num);
        maiores.push_back(num);
    }

    maiores.sort();

    maiores.pop_back();

    // acha lista de maiores

    // acha se o numero na posicao i esta na lista de maiores, se estiver joga-o para direita (caso o numero anterior a ele nao for maior tbm)

    return 0;
}