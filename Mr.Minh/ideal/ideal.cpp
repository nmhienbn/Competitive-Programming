#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "ideal"
const int maxn = 1e5 + 5;

using namespace std;

int n, m, h[maxn], b[maxn][20], l[maxn], res[maxn];
vector<pii> g[maxn];

int ss_LCA(int u, int v);

void dfs(int u){
    for (pii vt : g[u]){
        int v = vt.first;
        int w = vt.second;
        if (v == b[u][0]) continue;
        if (h[v] > h[u] + 1){
            h[v] = h[u] + 1;
            l[v] = w;
            b[v][0] = u;
            fi(i, 1, 17) b[v][i] = b[b[v][i - 1]][i - 1];
            dfs(v);
        }
        else if (h[v] == h[u] + 1){
            int p = ss_LCA(u, b[v][0]);
            if (p != b[v][0]){
                b[v][0] = u;
                fi(i, 1, 17) b[v][i] = b[b[v][i - 1]][i - 1];
                dfs(v);
            }
        }
    }
}

int ss_LCA(int u, int v){
    //    if (h[u] < h[v]) swap(u, v);
    //    int del = h[u] - h[v];
    //    fid(i, 17, 0) if (gb(del, i)){
    //        u = b[u][i];
    //    }
        if (u == v) return u;
        fid(i, 17, 0) if (b[u][i] != b[v][i]){
            u = b[u][i];
            v = b[v][i];
        }
        if (l[u] < l[v]) return u;
        return v;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, m){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    fi(i, 2, n) h[i] = 1e9;
    dfs(1);
    cout << h[n] << '\n';
    int last = n;
    fid(i, h[n], 1){
        res[i] = l[last];
        last = b[last][0];
    }
    fi(i, 1, h[n]) cout << res[i] << ' ';
}
