#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "stalingrad"
const int maxn = 4e5+5;
using namespace std;

int sub, n, q, in[maxn], out[maxn], b[maxn][23], cnt, dem,
    id, h[maxn], par[maxn], root, res, child[maxn], low[maxn];
vector<int> g[maxn];

struct cmp{
    bool operator () (const int& u, const int& v) const {
        return in[u] < in[v];
    }
};

set<int, cmp> s[maxn];

void dfs(int u){
    par[u] = root;
    in[u] = ++id;
    child[u] = 1;
    for (auto v : g[u]){
        h[v] = h[u] + 1;
        b[v][0] = u;
        fi(i, 1, 19) b[v][i] = b[b[v][i-1]][i-1];
        dfs(v);
        child[u] += child[v];
    }
    out[u] = ++id;
}

int LCA(int u, int v){
    if (h[u] < h[v]) swap(u, v);
    int d = h[u] - h[v];
    fid(i, 19, 0) if ((d >> i) & 1){
        u = b[u][i];
    }
    if (u == v) return u;
    fid(i, 19, 0) if (b[u][i] != b[v][i]){
        u = b[u][i];
        v = b[v][i];
    }
    return b[u][0];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> sub >> n >> q;
    fi(i, 2, n){
        int p;
        cin >> p;
        g[p].pb(i);
    }
    for (auto v : g[1]){
        root = v;
        h[v] = 1;
        dfs(v);
    }
    while (q--){
        char typ;
        int v;
        cin >> typ >> v;
        int u = par[v];
        if (typ == '+'){
            dem++;
            if (s[u].empty()) cnt++;
            else res -= child[low[u]];
            s[u].insert(v);
            int lca = LCA(*s[u].begin(), *(--s[u].end()));
            low[u] = lca;
            res += child[lca];
        }
        else {
            res -= child[low[u]];
            dem--;
            s[u].erase(v);
            if (s[u].empty()){
                cnt--;
                low[u] = 0;
            }
            else {
                int lca = LCA(*s[u].begin(), *(--s[u].end()));
                low[u] = lca;
                res += child[lca];
            }
        }
        cout << cnt << ' ' << res-dem << '\n';
    }
}
