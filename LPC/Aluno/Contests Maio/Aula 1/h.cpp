#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    while (cin >> a >> b)
    {
        cout << a << " " << b;
        if (a > b)
        {
            int auxTroca = a;
            a = b;
            b = auxTroca;
        }
        long int maxCont = 0;
        long int aux = a;
        while (b >= aux)
        {

            long int num = aux, cont = 0;
            while (num != 1)
            {
                cont++;
                if (num % 2)
                {
                    num = num * 3 + 1;
                }

                else
                {
                    num = num / 2;
                }
            };
            cont++;
            if (cont > maxCont)
                maxCont = cont;

            aux++;
        }
        cout << " " << maxCont << endl;
    }

    return 0;
}