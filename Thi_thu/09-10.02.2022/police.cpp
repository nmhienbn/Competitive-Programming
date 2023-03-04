#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define minimize(x, y) x = x > y ? y : x
#define pb push_back
#define Irelia "police"
const int maxn = 1e5 + 5;
using namespace std;

int n, m, q;
int low[maxn], num[maxn], id;
int in[maxn], out[maxn], id2;
vector<int> g[maxn];
int par[maxn][20], h[maxn];

void dfs(int u){
    low[u] = num[u] = ++id;
    in[u] = ++id2;
    for (int v : g[u]) if (v != par[u][0]){
        if (num[v])
            minimize(low[u], num[v]);
        else {
            par[v][0] = u;
            h[v] = h[u] + 1;
            fi(i, 1, 17) par[v][i] = par[par[v][i - 1]][i - 1];
            dfs(v);
            minimize(low[u], low[v]);
        }
    }
    out[u] = id2;
}

int Find(int u, int p){
    int x = h[u] - h[p] - 1;
    fid(i, 17, 0) if (gb(x, i)){
        u = par[u][i];
    }
    return u;
}

bool thuoc(int u, int v){
    return in[v] <= in[u] && out[u] <= out[v];
}

bool query(int a, int b, int c, int d){
    if (num[c] > num[d]) swap(c, d);
    if (par[d][0] != c) return true;
    if (low[d] <= num[c]) return true;
    if (thuoc(a, d) == thuoc(b, d)) return true;
    return false;

}
bool query(int a, int b, int c){
    if (num[a] > num[b]) swap(a, b);
    if (par[b][0] == a) return true;
    if (thuoc(b, a)){
        if (thuoc(b, c) && thuoc(c, a)){
            b = Find(b, c);
            if (low[b] < num[c]) return true;
            return false;
        }
        return true;
    }
    if (thuoc(c, a) || thuoc(c, b)) return true;
    if (thuoc(a, c) && thuoc(b, c)){
        a = Find(a, c);
        b = Find(b, c);
        if (a == b) return true;
        if (low[a] < num[c] && low[b] < num[c]) return true;
        return false;
    }
    if (thuoc(b, c)) swap(a, b);
    if (thuoc(a, c)){
        a = Find(a, c);
        if (low[a] < num[c]) return true;
        return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, m){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1);
    cin >> q;
    while (q--){
        int typ;
        cin >> typ;
        if (typ == 1){
            int u, v, a, b;
            cin >> u >> v >> a >> b;
            cout << (query(u, v, a, b) ? "yes\n" : "no\n");
        }
        else {
            int u, v, a;
            cin >> u >> v >> a;
            cout << (query(u, v, a) ? "yes\n" : "no\n");
        }
    }
}
