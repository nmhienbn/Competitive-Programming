#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "protect"
const int maxn = 3e5 + 5;
using namespace std;

int n, q, id, now, x, res, cnt, nex,
    a[maxn], h[maxn], lab[maxn], child[maxn],
    num[maxn], val[maxn], b[maxn][20], f[maxn];
vector<int> g[maxn];
set<int> s[maxn];
string typ;

void dfs(int u, int p){
    child[u] = 1;
    lab[u] = now;
    num[u] = ++id;
    val[id] = u;
    for (int v : g[u]){
        if (v == p) continue;
        h[v] = h[u] + 1;
        b[v][0] = u;
        fi(i, 1, 18) b[v][i] = b[b[v][i - 1]][i - 1];

        dfs(v, u);

        child[u] += child[v];
    }
}

int LCA(int u, int v){
    if (h[u] < h[v]) swap(u, v);
    int d = h[u] - h[v];
    fid(i, 18, 0) if (gb(d, i)){
        u = b[u][i];
    }
    if (u == v) return u;
    fid(i, 18, 0) if (b[u][i] != b[v][i]){
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
    cin >> n >> q;
    fi(i, 2, n){
        int v;
        cin >> v;
        g[i].pb(v);
        g[v].pb(i);
    }
    for (int v : g[1]){
        now = v;
        h[v] = 1;
        dfs(v, 1);
    }
    while (q--){
        cin >> typ >> x;
        int root = lab[x];
        int lca = 0;
        if (typ[0] == 'f'){
            if (s[root].empty()) res++;
            s[root].insert(num[x]);
            lca = LCA(val[*s[root].begin()], val[*s[root].rbegin()]);
        }
        else {
            s[root].erase(num[x]);
            if (s[root].empty()) res--;
            else lca = LCA(val[*s[root].begin()], val[*s[root].rbegin()]);
        }
        nex = child[lca] - s[root].size();
        cnt += nex - f[root];
        f[root] = nex;
        cout << res << ' ' << cnt << '\n';
    }
}
