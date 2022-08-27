#include <bits/stdc++.h>
using namespace std;
#define MAX 1000001
#define ll long long int

mt19937 rng((int)chrono::steady_clock::now().time_since_epoch().count());

const ll P = 1e18 + 9;
const ll b = uniform_int_distribution<ll>(0, P - 1)(rng);

inline ll mult(ll a, ll b, ll mod)
{
    return (a * b - (ll)((long double)a / mod * b) * mod + mod) % mod;
}

struct hash_str
{
    vector<ll> h, p;
    hash_str(string s) : h(s.size()), p(s.size())
    {
        int n = s.size();
        h[0] = s[0] + 128;
        p[0] = 1;
        for (int i = 1; i < n; i++)
        {
            h[i] = (mult(h[i - 1], b, P) + s[i] + 128) % P;
            p[i] = mult(p[i - 1], b, P);
        }
    }
    ll sub_hash(int l, int r)
    {
        if (l == 0)
            return h[r];
        ll ans = (h[r] - mult(h[l - 1], p[r - l + 1], P)) % P;
        if (ans < 0)
            ans += P;
        return ans;
    }
};

int main()
{
    string original, sub;
    int tam = 3;
    cin >> original;
    hash_str stringHash(original);
    int resposta = 0;
    for (int k = 0; k <= original.length() - tam; k++)
    {
        sub.clear();
        for (int f = 0; f < tam; f++)
        {
            sub += original[k + f];
        }
        // cout << sub << endl;

        hash_str subShash(sub);
        int n = original.size(), m = sub.size();
        int flag = 1;

        for (int i = 0; i < n - m + 1 && flag; i++)
        {
            ll a = subShash.sub_hash(i, i + m - 1), b = stringHash.sub_hash(0, m - 1);
            cout << endl
                 << sub << endl;
            cout << "string hash " << b << endl;
            cout << "subString Hash " << a << endl;

            if (subShash.sub_hash(i, i + m - 1) == stringHash.sub_hash(0, m - 1))
            {
                resposta++;
                flag = 0;
            }
        }
    }
    cout << resposta << endl;

    return 0;
}