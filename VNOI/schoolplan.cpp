#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "schoolplan"
const int maxn = 5e5 + 5;
using namespace std;

int n, m, q;
int h[maxn];
int b[maxn][20], d[maxn][20];
vector<pii> g[maxn];
bool cl[maxn];
pii E[maxn];
int root[maxn];

int find(int u){
    return root[u] == 0 ? u : root[u] = find(root[u]);
}
bool unify(int u, int v){
    u = find(u);
    v = find(v);
    if (u == v) return false;
    root[u] = v;
    return true;
}

void dfs(int u, int p){
    cl[u] = 1;
    for (pii vt : g[u]){
        int v = vt.first;
        int w = vt.second;
        if (cl[v]) continue;
        h[v] = h[u] + 1;
        b[v][0] = u;
        d[v][0] = w;
        fi(i, 1, 16){
            b[v][i] = b[b[v][i - 1]][i - 1];
            d[v][i] = min(d[v][i - 1], d[b[v][i - 1]][i - 1]);
        }
        dfs(v, u);
    }
}

pii get(int u, int v){
    if (h[u] < h[v]) swap(u, v);
    int del = h[u] - h[v];
    int m = 1e9;
    fid(i, 16, 0) if (gb(del, i)){
        m = min(m, d[u][i]);
        u = b[u][i];
    }
    if (u == v) return {u, m};
    fid(i, 16, 0) if (b[u][i] != b[v][i]){
        m = min({m, d[u][i], d[v][i]});
        u = b[u][i];
        v = b[v][i];
    }
    return {b[u][0], min({m, d[u][0], d[v][0]})};

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m >> q;
    fi(i, 1, m){
        cin >> E[i].first >> E[i].second;
    }
    fid(i, m, 1){
        int u = E[i].first, v = E[i].second;
        if (unify(u, v)){
            g[u].pb({v, i});
            g[v].pb({u, i});
        }
    }
    fi(i, 1, n) if (!cl[i])
        dfs(i, 0);
    while (q--){
        int u, v;
        cin >> u >> v;
        //cout << u << ' ' << v << '\n';
        if (find(u) != find(v)){
            cout << "0\n";
            continue;
        }
        pii ans = get(u, v);
        int len = h[u] + h[v] - h[ans.first] * 2;
        if (len & 1) cout << "0\n";
        else cout << ans.second << '\n';
    }
}
