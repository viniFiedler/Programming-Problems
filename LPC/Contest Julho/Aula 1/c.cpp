#include <bits/stdc++.h>
using namespace std;
#define MAX 201
int a[MAX], n, m;
char S[MAX], P[MAX];
void calculatePrefix()
{
    int i = 0, j = -1;
    a[0] = -1;
    while (i < m)
    {
        while (j >= 0 && P[i] != P[j])
            j = a[j];
        i++;
        j++;
        a[i] = j;
    }
}
int KMP()
{
    int i = 0, j = 0;
    calculatePrefix();
    while (i < n)
    {
        while (j >= 0 && S[i] != P[j])
            j = a[j];
        j++;
        i++;
        if (j == m)
            return i - m;
    }
    return -1;
}

int main()
{
    char header[201];
    char text[201];
    cin >> header;
    cin >> text;

    for (int i = 0; i < n; i++)
    {
    }
}