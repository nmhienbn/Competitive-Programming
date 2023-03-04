#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "cf_edu3e"
const int maxn = 2e5 + 5;
using namespace std;

struct dl {
    int u, v, w, t;
    bool operator < (const dl& x) const {
        return w < x.w;
    }
} a[maxn];

int n, m, root[maxn];
ll res, kq[maxn];
int b[maxn][20], h[maxn], d[maxn][20];
vector<pii> g[maxn];

int get_root(int u){
    return root[u] == 0 ? u : root[u] = get_root(root[u]);
}
bool unify(int u, int v){
    int p = get_root(u);
    int q = get_root(v);
    if (p == q) return false;
    root[p] = q;
    return true;
}

void dfs(int u){
    for (pii vt : g[u]){
        int v = vt.first, w = vt.second;
        if (v == b[u][0]) continue;
        b[v][0] = u;
        d[v][0] = w;
        h[v] = h[u] + 1;
        fi(i, 1, 17){
            b[v][i] = b[b[v][i - 1]][i - 1];
            d[v][i] = max(d[v][i - 1], d[b[v][i - 1]][i - 1]);
        }
        dfs(v);
    }
}

int LCA(int u, int v){
    if (h[u] < h[v]) swap(u, v);
    int del = h[u] - h[v];
    int ans = 0;
    fid(i, 17, 0) if (gb(del, i)){
        ans = max(ans, d[u][i]);
        u = b[u][i];
    }
    if (u == v) return ans;
    fid(i, 17, 0) if (b[u][i] != b[v][i]){
        ans = max({ans, d[u][i], d[v][i]});
        u = b[u][i];
        v = b[v][i];
    }
    return max({ans, d[u][0], d[v][0]});
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
        a[i] = {u, v, w, i};
    }
    sort(a + 1, a + m + 1);
    fi(i, 1, m) if (unify(a[i].u, a[i].v)){
        res += a[i].w;
        kq[a[i].t] = 1;
        g[a[i].u].pb({a[i].v, a[i].w});
        g[a[i].v].pb({a[i].u, a[i].w});
    }
    dfs(1);
    fi(i, 1, m){
        if (kq[a[i].t]) kq[a[i].t] = res;
        else kq[a[i].t] = res + a[i].w - LCA(a[i].u, a[i].v);
    }
    fi(i, 1, m) cout << kq[i] << '\n';
}
