// https://cses.fi/problemset/task/1094
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int size;
    long int moves = 0;
    vector<long int> values;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        long int a;
        cin >> a;
        values.push_back(a);
    }

    for (int i = 1; i < size; i++)
    {
        long int num = values[i - 1] - values[i];
        if (num > 0)
        {
            values[i] += num;
            moves += num;
        }
    }
    cout << moves << endl;
    return 0;
}