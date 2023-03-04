#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "lca"
const int maxn = 1e5 + 5;
using namespace std;

int n, st, m;
vector<int> g[maxn];
int b[maxn][20], h[maxn];

void dfs(int u, int p){
    for (int v : g[u]){
        if (v == p) continue;
        b[v][0] = u;
        h[v] = h[u] + 1;
        fi(i, 1, 17) b[v][i] = b[b[v][i - 1]][i - 1];
        dfs(v, u);
    }
}

int LCA(int u, int v){
    if (h[u] < h[v]) swap(u, v);
    int d = h[u] - h[v];
    fid(i, 17, 0) if (gb(d, i)){
        u = b[u][i];
    }
    if (u == v) return u;
    fid(i, 17, 0) if (b[u][i] != b[v][i]){
        u = b[u][i];
        v = b[v][i];
    }
    return b[u][0];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> st >> m;
    fi(i, 1, n - 1){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(st, 0);
    while (m--){
        int u, v;
        cin >> u >> v;
        cout << LCA(u, v) << '\n';
    }
}
