#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "bgame"
const int maxn = 1e5 + 5;
using namespace std;

struct dl {
    int u, v, w;
    bool operator < (const dl & x) const {
        return w > x.w;
    }
    int other (const int& x) {
        return u ^ v ^ x;
    }
};

int n, m, res;
int root[maxn]; //dsu
int b[maxn][20], d[maxn][20], h[maxn]; //lca
dl a[maxn];
vector<int> g[maxn];
bool cl[maxn], xd[maxn];

int get_root(int u){
    return root[u] == 0 ? u : root[u] = get_root(root[u]);
}

bool unify(int u, int v){
    int p = get_root(u);
    int q = get_root(v);
    if (p == q) return 0;
    root[p] = q;
    return 1;
}

void dfs(int u){
    cl[u] = 1;
    for (int i : g[u]) if (xd[i]){
        int v = a[i].other(u), w = a[i].w;
        if (cl[v]) continue;
        h[v] = h[u] + 1;
        b[v][0] = u;
        d[v][0] = w;
        fi(j, 1, 17){
            b[v][j] = b[b[v][j - 1]][j - 1];
            d[v][j] = max(d[v][j - 1], d[b[v][j - 1]][j - 1]);
        }
        dfs(v);
    }
}

int calc(int u, int v){
    int ans = 0;
    if (h[u] < h[v]) swap(u, v);
    int del = h[u] - h[v];
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
        a[i] = {u, v, w};
    }
    sort(a + 1, a + m + 1);
    fi(i, 1, m){
        if (unify(a[i].u, a[i].v)){
            xd[i] = 1;
            g[a[i].u].pb(i);
            g[a[i].v].pb(i);
        }
    }
    fi(i, 1, n) if (!cl[i]){
        dfs(i);
    }
    fi(i, 1, m) if (!xd[i]){
        int u = a[i].u;
        int v = a[i].v;
        int w = a[i].w;
        if (get_root(u) == get_root(v))
            res = max(res, calc(u, v) + w);
    }
    cout << res;
}
