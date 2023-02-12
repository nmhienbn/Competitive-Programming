#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int m, n, k;
vector<int> a[maxn];
vector<int> b[maxn];
vector<int> c[maxn];
pair<int, int> d[maxn];
int res;

inline int calc(int cl)
{
    int ans = 0;
    for (int i = 0; i <= m + 1; i++)
        c[i].assign(n + 2, 0);
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            c[i][j] += c[i - 1][j] + c[i][j - 1] - c[i - 1][j - 1];
            while ((a[i][j] + c[i][j]) % 3 != cl)
            {
                if (!b[i][j])
                    return 1e9;
                int u = d[b[i][j]].first;
                int v = d[b[i][j]].second;
                ans++;
                c[i][j]++;
                c[i][v + 1]--;
                c[u + 1][j]--;
                c[u + 1][v + 1]++;
            }
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> m >> n >> k;
    for (int i = 1; i <= m; i++)
        a[i].assign(n + 2, 0);
    for (int i = 1; i <= m; i++)
        b[i].assign(n + 2, 0);
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int i = 1; i <= k; i++)
    {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        d[i] = {x, y};
        b[u][v] = i;
    }
    int res = min(calc(1), calc(2));
    if (res != 1e9)
        cout << res;
    else
        cout << -1;
    return 0;
}
