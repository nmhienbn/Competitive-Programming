#include <bits/stdc++.h>
using namespace std;

const int maxn = 2005;
const int mod = 1e9 + 7;

int n, b, a[maxn];
long long f[maxn][maxn], res;

void add(long long &x, long long y)
{
    x += y;
    if (x >= mod)
        x -= mod;
}

void th1(int &i)
{
    for (int j = 0; j <= b; j++)
        f[i][j] = f[i + 1][j];
}

void th2(int &i)
{
    for (int j = 1; j <= b - a[i] + 1; j++)
        f[i][j] = f[i + 1][j - 1];
}

void th3(int &i)
{
    for (int j = 0; j <= b; j++)
        f[i][j] = f[i + 1][j];
    for (int j = 1; j <= b; j++)
        add(f[i][j], 1ll * f[i + 1][j - 1] * min(b - j + 1, i - 1) % mod);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("graph.inp", "r", stdin);
    freopen("graph.out", "w", stdout);
    cin >> n >> b;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    f[n + 1][0] = 1;
    for (int i = n; i >= 1; i--)
    {
        if (a[i] == 0)
            th1(i);
        else if (a[i] > 0)
            th2(i);
        else
            th3(i);
    }
    for (int i = 0; i <= b; i++)
        add(res, f[1][i]);
    cout << res;
}
