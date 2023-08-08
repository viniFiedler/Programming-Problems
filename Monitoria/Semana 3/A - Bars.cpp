#include <bits/stdc++.h>

#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

typedef long long ll;

using namespace std;
const ll mod = 1e9 + 7;

int main()
{
    fast_io;
    int num;
    vector<int> barras;
    cin >> num;
    int alta = -1;
    for (int i = 0; i < num; i++)
    {
        cin >> barras[i];
    }

    sort(barras.begin(), barras.end());
}