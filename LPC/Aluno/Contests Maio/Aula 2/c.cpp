#include <bits/stdc++.h>

using namespace std;

int main()
{
    bool reverse = false;

    int num;
    cin >> num;
    deque<int> lista;

    while (num--)
    {

        string ordem;
        cin >> ordem;

        if (ordem == "push_back")
        {
            if (!reverse)
            {
                int numero;
                cin >> numero;
                lista.push_back(numero);
            }
            else
            {
                int numero;
                cin >> numero;
                lista.push_front(numero);
            }
        }

        else if (ordem == "toFront")
        {
            if (!reverse)
            {
                int numero;
                cin >> numero;
                lista.push_front(numero);
            }
            else
            {
                int numero;
                cin >> numero;
                lista.push_back(numero);
            }
        }

        else if (ordem == "reverse")
        {
            reverse = !reverse;
        }

            {
                if (!reverse)
                {
                    printf("%d\n", lista.back());
                    lista.pop_back();
                }
                else
                {
                    printf("%d\n", lista.front());
                    lista.pop_front();
                }
            }
            else if (ordem == "front")
            {
                if (!reverse)
                {
                    printf("%d\n", lista.front());
                    lista.pop_front();
                }
                else
                {
                    printf("%d\n", lista.back());
                    lista.pop_back();
                }
            }
        }

        else
            printf("No job for Ada?\n");
    }
    return 0;
}