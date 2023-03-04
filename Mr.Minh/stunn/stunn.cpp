#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "stunn"
const int maxn = 1e5 + 5;

using namespace std;

int n, m, child[maxn], low[maxn],
    num[maxn], id;
ll res[maxn];
vector<int> g[maxn];

void minimize(int& x, int y){
    if (x > y) x = y;
}

void dfs(int u, int p){
    int sum = 0;
    child[u] = 1;
    num[u] = low[u] = ++id;
    res[u] = n * 2 - 2;
    for (int v : g[u]){
        if (v == p) continue;
        if (num[v]) minimize(low[u], num[v]);
        else {
            dfs(v, u);
            child[u] += child[v];
            minimize(low[u], low[v]);
            if (low[v] >= num[u]){
                sum += child[v];
                res[u] += 1ll * child[v] * (n - child[v] - 1);
            }
        }
    }
    res[u] += 1ll * sum * (n - sum - 1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, m){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1, 0);
    fi(u, 1, n){
        cout << res[u] << '\n';
    }
}
