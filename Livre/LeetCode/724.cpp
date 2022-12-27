#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {2, 1, -1};
    vector<int> Leftright;
    vector<int> Rightleft;

    int aux = 0;
    for (auto &i : nums)
    {
        aux += i;
        Leftright.push_back(aux);
    }

    reverse(nums.begin(), nums.end());
    aux = 0;

    for (auto &i : nums)
    {
        aux += i;
        Rightleft.push_back(aux);
    }
    for (int i = 0; i < Rightleft.size(); i++)
    {
        if (Rightleft[i] == Leftright[Rightleft.size() - i - 1])
            cout << ' ' << Rightleft[i] << ' ' << Leftright[Rightleft.size() - i - 1] << "\n";
    }

    cout << -1;

    return 0;
};