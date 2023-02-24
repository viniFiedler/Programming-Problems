// https://codeforces.com/problemset/problem/915/A
#include <bits/stdc++.h>
using namespace std;
// bem simples, o maior divisor é o melhor balde
// o importante é não pensar demais e dificultar o exercicio
// sol O(1)
int main()
{
    int nBaldes, tamanho;
    int divisor = -1;
    cin >> nBaldes >> tamanho;
    for (int i = 0; i < nBaldes; i++)
    {
        int num;
        cin >> num;
        if (num > divisor && tamanho % num == 0)
        {
            divisor = num;
        }
    }

    cout << tamanho / divisor << endl;

    return 0;
}