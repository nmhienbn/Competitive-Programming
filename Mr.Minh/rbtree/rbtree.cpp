#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "rbtree"
const int maxn = 2e5+5;
using namespace std;

int sub, nt, n, val[maxn], root[maxn], dis[maxn];
vector<int> g[maxn], edge[maxn];

int get_root(int u){
    return root[u] == 0 ? u : root[u] = get_root(root[u]);
}

void dfs(int u, int par){
    for (int v : g[u]){
        if (v == par) continue;
        if (val[v] == val[u]){
            root[v] = u;
        }
        else {
            int rt = get_root(u);
            edge[rt].pb(v);
            edge[v].pb(rt);
        }
        dfs(v, u);
    }
}

void dfs1(int u, int par){
    for (int v : edge[u]){
        if (v == par) continue;
        dis[v] = dis[u] + 1;
        dfs1(v, u);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> sub >> nt;
    while (nt--){
        cin >> n;
        fi(i, 1, n){
            root[i] = 0;
            g[i].clear();
            edge[i].clear();
        }
        fi(i, 1, n) cin >> val[i];
        fi(i, 1, n-1){
            int u, v;
            cin >> u >> v;
            g[u].pb(v);
            g[v].pb(u);
        }
        dfs(1, 0);

        fi(i, 1, n) dis[i] = 0;
        dfs1(1, 0);

        int vt = max_element(dis + 1, dis + n + 1) - dis;
        fi(i, 1, n) dis[i] = 0;
        dfs1(vt, 0);

        cout << (*max_element(dis + 1, dis + n + 1) + 1) / 2 << ' ';
    }
}
