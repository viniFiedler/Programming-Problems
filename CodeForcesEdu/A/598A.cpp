#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        long long int sum = -1;
        int number;
        cin >> number;

        for (int i = 2; i <= number; i++)
        {
            if (i != 0 && (i & (i - 1)) == 0)
                sum -= i;
            else
                sum += i;
        }

        cout << sum << endl;
    }

    return 0;
}