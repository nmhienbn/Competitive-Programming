#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "knights"
const int maxn = 3005, maxm = 1e5 + 5;
using namespace std;

struct dl {
    int u, v, w;
    bool operator < (const dl& x) const {
        return w < x.w;
    }
};

int n, m, q;
dl a[maxm];
int lab[maxn];
vector<pii> g[maxn];
int h[maxn], b[maxn][15], d[maxn][15];

int Find(int u){
    return lab[u] < 0 ? u : lab[u] = Find(lab[u]);
}
bool unify(int p, int q){
    p = Find(p);
    q = Find(q);
    if (p == q) return 0;
    if (lab[p] > lab[q]) swap(p, q);
    lab[p] += lab[q];
    lab[q] = p;
    return 1;
}

void dfs(int u){
    for (pii vt : g[u]) if (vt.first != b[u][0]){
        int v = vt.first, w = vt.second;
        b[v][0] = u;
        d[v][0] = w;
        h[v] = h[u] + 1;
        fi(i, 1, 12){
            b[v][i] = b[b[v][i - 1]][i - 1];
            d[v][i] = max(d[v][i - 1], d[b[v][i - 1]][i - 1]);
        }
        dfs(v);
    }
}
int calc(int u, int v){
    if (h[u] < h[v]) swap(u, v);
    int x = h[u] - h[v];
    int res = 0;
    fid(i, 12, 0) if (gb(x, i)){
        res = max(res, d[u][i]);
        u = b[u][i];
    }
    if (u == v) return res;
    fid(i, 12, 0) if (b[u][i] != b[v][i]){
        res = max({res, d[u][i], d[v][i]});
        u = b[u][i];
        v = b[v][i];
    }
    return max({res, d[u][0], d[v][0]});
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, n) lab[i] = -1;
    fi(i, 1, m){
        cin >> a[i].u >> a[i].v >> a[i].w;
    }
    sort(a + 1, a + m + 1);
    fi(i, 1, m){
        int u = a[i].u, v = a[i].v;
        if (unify(u, v)){
            g[u].pb({v, a[i].w});
            g[v].pb({u, a[i].w});
        }
    }
    dfs(1);
    cin >> q;
    while (q--){
        int u, v;
        cin >> u >> v;
        cout << calc(u, v) << '\n';
    }
}
