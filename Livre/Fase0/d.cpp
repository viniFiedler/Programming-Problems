#include <bits/stdc++.h>
using namespace std;

int main()
{
    string palavra;
    string palavra_01, palavra_02, palavra_03, palavra_04, palavra_05;
    int aluno[5] = {0, 0, 0, 0, 0}, num_palavras;
    cin >> num_palavras;
    for (int i = 0; i < num_palavras; i++)
    {
        cin >> palavra;
        cin >> palavra_01 >> palavra_02 >> palavra_03 >> palavra_04 >> palavra_05;
        if (palavra_01 == palavra)
        {
            aluno[0] += 1;
        }
        if (palavra_02 == palavra)
        {
            aluno[1] += 1;
        }
        if (palavra_03 == palavra)
        {
            aluno[2] += 1;
        }
        if (palavra_04 == palavra)
        {
            aluno[3] += 1;
        }
        if (palavra_05 == palavra)
        {
            aluno[4] += 1;
        }
        else
        {
            int diferenca[5] = {0, 0, 0, 0, 0}, k = 0;
            while (palavra[k] != '\0')
            {
                if (palavra_01[k] != palavra[k])
                {
                    diferenca[0] += 1;
                }
                if (palavra_02[k] != palavra[k])
                {
                    diferenca[1] += 1;
                }
                if (palavra_03[k] != palavra[k])
                {
                    diferenca[2] += 1;
                }
                if (palavra_04[k] != palavra[k])
                {
                    diferenca[3] += 1;
                }
                if (palavra_05[k] != palavra[k])
                {
                    diferenca[4] += 1;
                }
            }
            int menor = diferenca[0];
            for (k = 1; k < 5; k++)
            {
                if (diferenca[k] < menor)
                {
                    menor = diferenca[k];
                }
            }
            for (k = 0; k < 5; k++)
            {
                if (diferenca[k] == menor)
                {
                    aluno[k] += 0.5;
                }
            }
        }
    }
    int maior;
    maior = aluno[0];
    for (int j = 0; j < 5; j++)
    {
        if (aluno[j] > maior)
        {
            maior = aluno[j];
        }
    }
    cout << maior << "\n";
    for (int i = 0; i < 5; i++)
    {
        if (aluno[i] == maior)
        {
            cout << i + 1 << " ";
        }
    }
    cout << "\n";
    return 0;
}