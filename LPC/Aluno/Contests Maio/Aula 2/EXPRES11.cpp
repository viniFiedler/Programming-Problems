#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, i;
    string s;
    cin >> n;

    while (n--)
    {
        cin >> s;
        stack<char> p;
        int tam = s.size();
        for (i = 0; i < tam; i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                p.push(s[i]);
            }

            else if (p.empty())
                break;

            else if (s[i] == ')' && p.top() == '(' ||
                     s[i] == '}' && p.top() == '{' ||
                     s[i] == ']' && p.top() == '[')
                p.pop();

            else
                break;
        }

        if (p.empty() && i == s.size())
        {
            cout << "S\n";
        }

        else
            cout << "N\n";
    }
    return 0;
}