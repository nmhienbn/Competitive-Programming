#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 5, maxl = 1e6 + 5, maxm = 1e5 + 5;

int n, m, id;
int a[maxn], vt[maxn];
long long dp[maxn], res;
long long c[maxm], f[maxm];
string s;
vector<int> g[maxm], gg[maxm];

struct node
{
    int child[26];
    long long val;
    int pre;
} T[maxl];

void add(string s, int i)
{
    int x = 0;
    for (char c : s)
    {
        int now = c - 'A';
        if (!T[x].child[now])
            T[x].child[now] = ++id, T[id].pre = x;
        x = T[x].child[now];
    }
    vt[i] = x;
}

void update(int x, long long val)
{
    while (x > 0)
    {
        x = T[x].pre;
        T[x].val = max(T[x].val, val);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        add(s, i);
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int qt = sqrt(m);
    for (int u = 1; u <= 100000; u++)
    {
        for (int v : g[u])
            if (g[v].size() >= qt)
            {
                gg[u].push_back(v);
            }
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i] = max(T[vt[i]].val, c[a[i]]) + a[i];
        for (int x : gg[a[i]])
        {
            dp[i] = max(dp[i], f[x] + a[i]);
        }
        update(vt[i], dp[i]);
        if (g[a[i]].size() < qt)
        {
            for (int v : g[a[i]])
            {
                c[v] = max(c[v], dp[i]);
            }
        }
        else
        {
            f[a[i]] = max(f[a[i]], dp[i]);
        }
        res = max(res, dp[i]);
    }
    cout << res;
    return 0;
}
