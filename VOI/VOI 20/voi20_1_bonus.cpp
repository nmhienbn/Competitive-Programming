#include <bits/stdc++.h>
using namespace std;
const int maxn = 305;
int n, k, a[maxn];
long long L[maxn][maxn][maxn];

long long calc(int i, int j, int k)
{
    if (i > j && k > 0)
        return -1e18;
    if (L[i][j][k] != -1)
        return L[i][j][k];
    long long best = max(calc(i + 1, j, k), calc(i, j - 1, k));
    if (j - i >= 1 && k > 0)
        best = max({best,
                    calc(i + 1, j - 1, k - 1) + abs(a[i] - a[j]),
                    calc(i + 2, j, k - 1) + abs(a[i] - a[i + 1]),
                    calc(i, j - 2, k - 1) + abs(a[j] - a[j - 1])});
    return L[i][j][k] = best;
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            for (int t = 1; t <= k; t++)
                L[i][j][t] = -1;
        }
    }
    cout << calc(1, n, k);
    return 0;
}
