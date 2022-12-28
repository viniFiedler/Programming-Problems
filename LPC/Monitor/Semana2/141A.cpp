#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Contador de letras posicao 0 eh o A, 1 eh o B, e assim vai
    vector<int> Letras;
    Letras.resize(26);

    char convidados[101] = {-1}, host[101] = {-1}, naPorta[101] = {-1};
    // o número precisa ser 101 pois ha um \n no final de cada cadeia de char

    scanf("%s", convidados);
    scanf("%s", host);
    scanf("%s", naPorta);

    int tamanho = strlen(convidados);

    for (int i = 0; i < tamanho; i++)
    {
        // - 65 pois é o valor na tabela ascii para A maisuclo
        Letras[convidados[i] - 65]++;
    }

    tamanho = strlen(host);

    for (int i = 0; i < tamanho; i++)
    {
        Letras[host[i] - 65]++;
    }

    tamanho = strlen(naPorta);

    for (int i = 0; i < tamanho; i++)
    {
        int cont = naPorta[i] - 65;
        Letras[cont]--;
        if (Letras[cont] < 0)
        {
            printf("NO\n");
            return 0;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (Letras[i] != 0)
        {
            printf("NO\n");
            return 0;
        }
    }

    printf("YES\n");
    return 0;
}