#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "tree"
const int maxn = 1e5+5;

using namespace std;

int n, q, b[maxn][20], h[maxn], d[maxn], a[10], res, dem[maxn];
bool c[10];
vector<pii> g[maxn];

void dfs(int u){
    for (auto vt : g[u]){
        int v = vt.first, w = vt.second;
        if (h[v]) continue;
        d[v] = d[u] + w;
        h[v] = h[u] + 1;
        b[v][0] = u;
        fi(i, 1, 16){
            b[v][i] = b[b[v][i-1]][i-1];
        }
        dfs(v);
    }
}

int LCA(int u, int v){
    if (h[u] < h[v]) swap(u, v);
    int del = h[u] - h[v];
    fid(i, 16, 0){
        if ((del >> i) & 1){
            u = b[u][i];
        }
    }
    if (u == v) return u;
    fid(i, 16, 0){
        if (b[u][i] != b[v][i]){
            u = b[u][i];
            v = b[v][i];
        }
    }
    return b[u][0];
}

void xuli(){
    int cnt = 0, lca = 0;
    fi(i, 1, 5){
        if (c[i]){
            cnt++;
            if (lca == 0) lca = a[i];
            else lca = LCA(lca, a[i]);
        }
    }
    if (cnt == 5) return;
    if (cnt&1) res += d[lca];
    else res -= d[lca];
}

void ql(int i){
    fi(j, 0, 1){
        c[i] = j;
        if (i == 5) xuli();
        else ql(i+1);
    }
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    fi(i, 1, n-1){
        int u, v, w;
        cin >> u >> v >> w;
        u++, v++;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    h[1] = 1;
    dfs(1);
    cin >> q;
    while (q--){
        res = 0;
        fi(i, 1, 5) cin >> a[i], a[i]++;
        ql(1);
        cout << res << '\n';
    }
}
