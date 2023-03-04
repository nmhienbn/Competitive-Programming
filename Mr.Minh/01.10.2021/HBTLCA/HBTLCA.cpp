#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "HBTLCA"
const int maxn = 1e5+5;

using namespace std;

int n, m, d[maxn], b[maxn][20];
vector<int> g[maxn];

void dfs(int u){
    for (auto v : g[u]){
        if (d[v]) continue;
        d[v] = d[u] + 1;
        b[v][0] = u;
        fi(i, 1, 17) b[v][i] = b[b[v][i-1]][i-1];
        dfs(v);
    }
}

int LCA(int u, int v){
    if (d[u] < d[v]) swap(u, v);
    int del = d[u] - d[v];
    fid(i, 17, 0){
        if ((del >> i) & 1){
            u = b[u][i];
        }
    }
    if (u == v) return u;
    fid(i, 17, 0){
        if (b[u][i] != b[v][i]){
            u = b[u][i];
            v = b[v][i];
        }
    }
    return b[u][0];
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    while (cin >> n){
        if (n == 0) break;
        fi(i, 1, n) g[i].clear(), d[i] = 0;
        fi(i, 1, n) fi(j, 0, 17) b[i][j] = 0;
        fi(i, 2, n){
            int u, v;
            cin >> u >> v;
            g[u].pb(v);
            g[v].pb(u);
        }
        d[1] = 1;
        dfs(1);
        int root = 1;
        cin >> m;
        while (m--){
            char typ;
            int u, v;
            cin >> typ >> u;
            if (typ == '!'){
                root = u;
            }
            else {
                cin >> v;
                int tu = LCA(u, root), tv = LCA(v, root), uv = LCA(u, v);
                int res = (d[tu] >= d[tv] ? tu : tv);
                res = (d[res] >= d[uv] ? res : uv);
                cout << res << '\n';
            }
        }
    }
}
