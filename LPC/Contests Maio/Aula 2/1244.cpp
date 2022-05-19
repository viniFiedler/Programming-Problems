#include <bits/stdc++.h>
#include <list>
#include <string>
using namespace std;

bool ordem(string &s1, string &s2)
{
    return s1 < s2;
}
int main()
{
    int num;

    cin >> num;
    cin >> ws;
    list<string> lista;
    while (num--)
    {
        string aux;
        getline(cin, aux);
        lista.push_back(aux);
    }
    int n;
    for (int i = 0; i < n; i++)
    {
        cout << lista.front() << endl;
        lista.pop_front();
    }
    return 0;
}