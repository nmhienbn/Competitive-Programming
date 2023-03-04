#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "gather"
const int maxn = 1e5 + 5;
using namespace std;

int n, a[maxn], child[maxn], sum;
ll f[maxn], h[maxn], res = 1e18;
vector<pii> g[maxn];

void dfs(int u, int p){
    child[u] = a[u];
    for (pii vt : g[u]){
        int v = vt.first, w = vt.second;
        if (v == p) continue;
        dfs(v, u);
        child[u] += child[v];
        f[u] += f[v] + 1ll * child[v] * w;
    }
}

void dfs1(int u, int p){
    for (pii vt : g[u]){
        int v = vt.first, w = vt.second;
        if (v == p) continue;
        h[v] = h[u] + f[u] - f[v] + 1ll * (sum - child[v] * 2) * w;
        dfs1(v, u);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i], sum += a[i];
    fi(i, 2, n){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    dfs(1, 0);
    dfs1(1, 0);
    fi(i, 1, n){
        res = min(res, f[i] + h[i]);
    }
    cout << res;
}
