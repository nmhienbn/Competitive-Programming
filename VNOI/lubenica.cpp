#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "lubenica"
const int maxn = 1e5 + 5;
using namespace std;

int n, q;
int h[maxn];
int b[maxn][20], d[maxn][20], f[maxn][20];
vector<pii> g[maxn];

void dfs(int u, int p){
    for (pii vt : g[u]){
        int v = vt.first;
        int w = vt.second;
        if (v == p) continue;
        h[v] = h[u] + 1;
        b[v][0] = u;
        d[v][0] = f[v][0] = w;
        fi(i, 1, 16){
            b[v][i] = b[b[v][i - 1]][i - 1];
            d[v][i] = min(d[v][i - 1], d[b[v][i - 1]][i - 1]);
            f[v][i] = max(f[v][i - 1], f[b[v][i - 1]][i - 1]);
        }
        dfs(v, u);
    }
}

void query(int u, int v){
    if (h[u] < h[v]) swap(u, v);
    int del = h[u] - h[v];
    int m = 1e9, M = 0;
    fid(i, 16, 0) if (gb(del, i)){
        m = min(m, d[u][i]);
        M = max(M, f[u][i]);
        u = b[u][i];
    }
    if (u == v){
        cout << m << ' ' << M << '\n';
        return;
    }
    fid(i, 16, 0) if (b[u][i] != b[v][i]){
        m = min({m, d[u][i], d[v][i]});
        M = max({M, f[u][i], f[v][i]});
        u = b[u][i];
        v = b[v][i];
    }
    cout << min({m, d[u][0], d[v][0]}) << ' ' << max({M, f[u][0], f[v][0]}) << '\n';
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 2, n){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    dfs(1, 0);
    cin >> q;
    while (q--){
        int u, v;
        cin >> u >> v;
        query(u, v);
    }
}
