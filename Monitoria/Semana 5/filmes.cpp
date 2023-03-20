#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    vector<pair<int, pair<int, int>>> tempos;

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        int a, b;

        cin >> a >> b;

        tempos.push_back(make_pair(b - a, make_pair(a, b)));
    }

    sort(tempos.begin(), tempos.end());

    for (int i = 0; i < n; i++)
    {
        cout << tempos[i].first << " " << tempos[i].second.first << " " << tempos[i].second.second << endl;
    }

    return 0;
}