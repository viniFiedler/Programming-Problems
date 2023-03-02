//  https://open.kattis.com/problems/sim
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    int testes;
    scanf("%d\n", &testes);

    while (testes--)
    {
        stack<char> pilhaPrincipal, PilhaSecundaria;

        string letras;
        getline(cin, letras);
        int tamanho = letras.size();
        char letra;
        for (int i = 0; i < tamanho; i++)
        {
            letra = letras[i];
            if (letra != '\n')
            {

                if (letra != ']' && letra != '[' && letra != '<')
                {
                    pilhaPrincipal.push(letra);
                }

                else if (letra == '<' && !pilhaPrincipal.empty())
                {
                    pilhaPrincipal.pop();
                }

                else if (letra == '[')
                {
                    while (!pilhaPrincipal.empty())
                    {
                        PilhaSecundaria.push(pilhaPrincipal.top());
                        pilhaPrincipal.pop();
                    }
                }

                else if (letra == ']')
                    while (!PilhaSecundaria.empty())
                    {
                        pilhaPrincipal.push(PilhaSecundaria.top());
                        PilhaSecundaria.pop();
                    }
            }
        }

        while (!pilhaPrincipal.empty())
        {
            PilhaSecundaria.push(pilhaPrincipal.top());
            pilhaPrincipal.pop();
        }

        while (!PilhaSecundaria.empty())
        {
            cout << PilhaSecundaria.top();
            PilhaSecundaria.pop();
        }
        cout << "\n";
    }

    return 0;
}