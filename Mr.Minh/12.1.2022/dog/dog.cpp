#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "dog"
const int maxn = 1e5 + 5;
using namespace std;

int n, f[maxn], d[maxn], e[maxn];
vector<pii> g[maxn];

void dfs(int u, int p){
    for (pii vt : g[u]){
        int v = vt.first, w = vt.second;
        if (v == p) continue;
        dfs(v, u);
        if (f[u] < f[v] + w){
            d[u] = f[u];
            f[u] = f[v] + w;
        }
        else if (d[u] < f[v] + w){
            d[u] = f[v] + w;
        }
    }
}

void dfs2(int u, int p){
    for (pii vt : g[u]){
        int v = vt.first, w = vt.second;
        if (v == p) continue;
        if (f[u] == f[v] + w){
            e[v] = d[u] + w;
        }
        else {
            e[v] = f[u] + w;
        }
        e[v] = max(e[v], e[u] + w);
        dfs2(v, u);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n - 1){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    dfs(1, 0);
    dfs2(1, 0);
    fi(i, 1, n){
        cout << max(f[i], e[i]) << ' ';
    }
}
