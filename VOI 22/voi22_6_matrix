#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7 + 5, mod = 1e9 + 7;

int m, n;
long long res;
int cnt[35], mu[35];
int p[maxn], dem;

void add(long long &x, long long y)
{
    x = (x + y) % mod;
}

void Eratosthenes()
{
    for (int i = 2; i <= 4000; i++)
        if (!p[i])
        {
            p[i] = ++dem;
            for (int j = i * i; j < maxn; j += i)
                if (!p[j])
                {
                    p[j] = dem;
                }
        }

    for (int i = 4001; i <= 10000000; i++)
        if (!p[i])
        {
            p[i] = ++dem;
        }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("matrix.inp", "r", stdin);
    freopen("matrix.out", "w", stdout);
    Eratosthenes();
    cin >> m >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= 30; j++)
            cnt[j] += (p[i] >> j) & 1;

    for (int i = 0; i <= 30; i++)
        mu[i] = 1 << i;

    for (int i = 1; i <= m; i++)
        for (int j = 0; j <= 30; j++)
            if ((p[i] >> j) & 1)
            {
                add(res, (long long)(n - cnt[j]) * mu[j]);
            }
            else
            {
                add(res, (long long)cnt[j] * mu[j]);
            }

    add(res, (long long)m * n);
    cout << res;
    return 0;
}
