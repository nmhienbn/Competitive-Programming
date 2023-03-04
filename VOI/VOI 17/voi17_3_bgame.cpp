#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int nt, n, k, f[maxn];
long long st;
int vt[maxn];

struct matrix
{
    long long a[2][2];
    matrix operator*(const matrix &B) const
    {
        matrix C;
        for (int i = 0; i <= 1; i++)
            for (int j = 0; j <= 1; j++)
            {
                C.a[i][j] = 0;
                for (int t = 0; t <= 1; t++)
                    C.a[i][j] = (C.a[i][j] + a[i][t] * B.a[t][j]) % k;
            }
        return C;
    }
    matrix binpow(long long k) const
    {
        if (k == 1)
            return *this;
        matrix tg = this->binpow(k >> 1);
        tg = tg * tg;
        if (k & 1)
            return tg * (*this);
        return tg;
    }
};

matrix cs, A;

int add(int x, int y)
{
    x += y;
    if (x >= k)
        return x - k;
    return x;
}

void solve()
{
    cin >> n >> st >> k;
    A = cs.binpow(st);
    f[1] = A.a[1][0];
    f[2] = A.a[0][0];
    for (int i = 3; i <= n; i++)
        f[i] = add(f[i - 1], f[i - 2]);
    for (int i = 2; i <= n; i++)
        f[i] = add(f[i], f[i - 1]);
    for (int i = 0; i <= n; i++)
    {
        vt[i] = -1;
    }
    for (int i = 0; i <= n; i++)
    {
        if (~vt[f[i]])
        {
            cout << i - vt[f[i]] << ' ';
            for (int j = vt[f[i]]; j <= i - 1; j++)
                cout << st + j << ' ';
            cout << '\n';
            return;
        }
        else
            vt[f[i]] = i;
    }
}

int main()
{
    cin >> nt;
    cs.a[0][0] = 1;
    cs.a[0][1] = 1;
    cs.a[1][0] = 1;
    while (nt--)
    {
        solve();
    }
    return 0;
}
