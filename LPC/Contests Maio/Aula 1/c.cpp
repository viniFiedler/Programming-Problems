#include <bits/stdc++.h>
using namespace std;

int main()
{

    int numero;
    while (cin >> numero)
    {

        int a = 0;
        int b = 0;

        while (numero / 2 >= 1)
        {
            a += numero / 2;
            numero = numero / 2;
            cout << numero << " " << a << " " << b << endl;
            if (numero / 2 >= 0)
            {
                b += numero / 2;
                        }
            numero = numero / 2;
            cout << numero << " " << a << " " << b << endl;
        }

        cout << a << " " << b << endl;
    };

    return 0;
}