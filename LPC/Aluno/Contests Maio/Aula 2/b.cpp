#include <bits/stdc++.h>

using namespace std;

int main()
{
    string num;
    while (getline(cin, num))
    {
        stack<int> pilha;
        bool erro = false;
        vector<int> verificaTamanho;
        stringstream teste(num);
        int numero;
        vector<int> num;
        int tam = 0;
        while (teste >> numero)
        {
            num.push_back(numero);
            if (numero < 0)
                pilha.push(numero);
            else
            {
                if (pilha.empty() || pilha.top() + numero != 0)
                {
                    erro = true;
                    break;
                }
                else
                {
                    pilha.pop();
                }
            }
            verificaTamanho.push_back(numero);
            tam++;
        }

        for (int i = 0; i < tam && !erro; i++)
        {
            if (verificaTamanho[i] > 0)
            {
                // printf("Vendo Boneca [%d] = %d \n", i, verificaTamanho[i]);
                int somaBonecas = 0;
                int qtndDeNumeros = 0;
                for (int j = i - 1; j >= 0; j--)
                {
                    if (-verificaTamanho[j] == verificaTamanho[i])
                    {
                        // printf("Fim dessa boneca %d \n", -verificaTamanho[j]);
                        break;
                    }
                    else if (verificaTamanho[j] > 0)
                    {
                        if (qtndDeNumeros == 0)
                            somaBonecas += verificaTamanho[j];
                        qtndDeNumeros++;
                    }
                    else
                        qtndDeNumeros--;
                }
                // printf("Soma das bonecas = %d \n", somaBonecas);

                if (somaBonecas >= verificaTamanho[i])
                {
                    erro = true;
                }
            }
        }

        if (!pilha.empty() || erro)
            printf(":-( Try again.\n");

        else
            printf(":-) Matrioshka!\n");
    }

    return 0;
}