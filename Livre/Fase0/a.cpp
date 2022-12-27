#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
    {
        string nome;
        float p1 = 0;
        float p2 = 0;
        float p3 = 0;
        float p4 = 0;
        float media = 0;

        string linha;

        getline(cin, nome);
        getline(cin, linha);
        istringstream os(linha);
        queue<float> fim;
        float temp;

        while (os >> temp)
            fim.push(temp);
        int tam = fim.size();

        if (tam == 0)
        {
            media = 0;
        }
        else if (tam == 1)
        {
            media = fim.front() / 2;
        }
        else if (tam == 2)
        {
            media = fim.front();
            fim.pop();
            media += fim.front();
            media /= 2;
        }
        else if (tam == 3)
        {
            media = fim.front();
            fim.pop();
            media += fim.front();
            fim.pop();
            media += fim.front();
            media /= 3;
        }
        else if (tam == 4)
        {
            set<float> m4;

            m4.insert(fim.front());
            fim.pop();
            m4.insert(fim.front());
            fim.pop();
            m4.insert(fim.front());
            fim.pop();
            m4.insert(fim.front());
            auto it = m4.end();
            it--;
            media += *it;
            it--;
            media += *it;
            it--;
            media += *it;
            media /= 3;
        }

        cout << nome << ": ";
        printf("%.1f\n", media);
    }

    return 0;
}