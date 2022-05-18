#include <bits/stdc++.h>

using namespace std;

int main()
{
    string num;
    while (getline(cin, num))
    {
        stringstream teste(num);
        int numero;
        vector<int> num;
        while (teste >> numero)
        {
            num.push_back(numero);
            cout << numero << endl;
        }
    }

    return 0;
}