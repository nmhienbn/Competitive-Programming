#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const long long INF = 1e18;

struct dl
{
    int u, v, w;
};

int n, m, st, fn, delta;
dl E[maxn];
vector<int> g[maxn];
long long f[maxn];
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;

void minimize(int v, long long s)
{
    if (f[v] > s)
    {
        f[v] = s;
        q.push({f[v], v});
    }
}

void Dijkstra()
{
    f[st] = 0;
    q.push({0, st});
    while (q.size())
    {
        int u = q.top().second;
        if (f[u] < q.top().first)
        {
            q.pop();
            continue;
        }
        if (u == fn)
        {
            cout << f[fn];
            exit(0);
        }
        q.pop();
        for (int i : g[u])
        {
            int v = E[i].v, w = E[i].w;
            if (u != st)
                w += i;
            if (v != fn)
                w += delta * i;
            minimize(v, f[u] + w);
        }
    }
    cout << -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> m >> st >> fn >> delta;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        E[i] = {u, v, w};
        g[u].push_back(i);
    }
    for (int i = 1; i <= n; i++)
        f[i] = INF;
    Dijkstra();
    return 0;
}
