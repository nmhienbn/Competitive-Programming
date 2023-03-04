#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "paracel-islands"
const int maxn = 3e5+5;
using namespace std;

int sub, n, q, h[maxn], b[maxn][20], d[maxn], par[maxn];
bool kt[2005][2005];
int t1[maxn], t2[maxn];
vector<pii> g[maxn];

void dfs(int u){
    for (pii vt : g[u]){
        int v = vt.first, w = vt.second;
        if (v == b[u][0]) continue;
        h[v] = h[u] + 1;
        d[v] = d[u] + w;
        b[v][0] = u;
        par[v] = u;
        fi(i, 1, 17) b[v][i] = b[b[v][i-1]][i-1];
        dfs(v);
    }
}

int LCA(int u, int v){
    if (h[u] < h[v]) swap(u, v);
    int d = h[u] - h[v];
    fid(i, 17, 0) if ((d >> i) & 1){
        u = b[u][i];
    }
    if (u == v) return u;
    fid(i, 17, 0) if (b[u][i] != b[v][i]){
        u = b[u][i];
        v = b[v][i];
    }
    return b[u][0];
}

int dis(int u, int v, int lca){
    return d[u] + d[v] - d[lca]*2;
}

inline bool in(int l, int x, int r){
    return l <= x && x <= r;
}

void solve(){
    memset(kt, 0, sizeof(kt));
    int b1, e1, s1, b2, e2, s2;
    cin >> b1 >> e1 >> s1 >> b2 >> e2 >> s2;
    int v1 = LCA(b1, e1);
    int v2 = LCA(b2, e2);
    int bd1 = b1;
    int bd2 = b2;
    while (b1 != v1){
        kt[b1][par[b1]] = 1;
        kt[par[b1]][b1] = 1;
        b1 = par[b1];
    }
    while (e1 != v1){
        kt[par[e1]][e1] = 1;
        kt[e1][par[e1]] = 1;
        e1 = par[e1];
    }
    while (b2 != v2){
        if (kt[b2][par[b2]]){
            int l1 = s1 + dis(bd1, b2, v1);
            int r1 = s1 + dis(bd1, par[b2], v1);
            if (l1 > r1) swap(l1, r1);
            int l2 = s2 + dis(bd2, b2, v2);
            int r2 = s2 + dis(bd2, par[b2], v2);
            if (l2 > r2) swap(l2, r2);
            //cout << l1 << ' ' << r1 << ' ' << l2 << ' ' << r2 << '\n';
            if (in(l2, l1, r2) || in(l2, r1, r2) || in(l1, l2, r1) || in(l1, r2, r1)){
                cout << "Y";
                return;
            }
        }
        b2 = par[b2];
    }
    while (e2 != v2){
        if (kt[e2][par[e2]]){
            int l1 = s1 + dis(bd1, e2, v1);
            int r1 = s1 + dis(bd1, par[e2], v1);
            if (l1 > r1) swap(l1, r1);
            int l2 = s2 + dis(bd2, e2, v2);
            int r2 = s2 + dis(bd2, par[e2], v2);
            if (l2 > r2) swap(l2, r2);
            //cout << l1 << ' ' << r1 << ' ' << l2 << ' ' << r2 << '\n';
            if (in(l2, l1, r2) || in(l2, r1, r2) || in(l1, l2, r1) || in(l1, r2, r1)){
                cout << "Y";
                return;
            }
        }
        e2 = par[e2];
    }
    cout << "N";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> sub >> n >> q;
    fi(i, 1, n-1){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    dfs(1);
    fi(i, 1, q){
        solve();
    }

}
