#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "nkpolice"
const int maxn = 1e5+5;

using namespace std;

int n, m, q, num[maxn], low[maxn], id, par[maxn],
    in[maxn], out[maxn], id2, b[maxn][20];
bool kt[maxn];
vector<int> g[maxn];

void dfs(int u){
    int child = (par[u] != -1);
    in[u] = ++id2;
    num[u] = low[u] = ++id;
    for (int v : g[u]){
        if (par[u] == v) continue;
        if (num[v]){
            low[u] = min(low[u], num[v]);
        }
        else {
            par[v] = u;
            b[v][0] = u;
            fi(i, 1, 17) b[v][i] = b[b[v][i-1]][i-1];
            dfs(v);
            low[u] = min(low[u], low[v]);
            if (low[v] >= num[u]) child++;
        }
    }
    if (child >= 2) kt[u] = 1;
    out[u] = ++id2;
}

bool thuoc(int u, int v){
    return in[v] <= in[u] && out[u] <= out[v];
}

int find_par(int u, int p){
    fid(i, 17, 0){
        int v = b[u][i];
        if (v > 0 && v != p && thuoc(v, p)) u = v;
    }
    return u;
}

bool solve1(int a, int b, int c, int d){
    if (num[c] > num[d]) swap(c, d);
    if (par[d] != c) return true;
    if (low[d] <= num[c]) return true;
    if (thuoc(a, d) == thuoc(b, d)) return true;
    return false;
}

bool solve2(int a, int b, int c){
    if (num[a] > num[b]) swap(a, b);
    if (par[b] == a) return true;
    if (thuoc(b, a)){
        if (thuoc(b, c) && thuoc(c, a)){
            b = find_par(b, c);
            if (low[b] < num[c]) return true;
            return false;
        }
        return true;
    }
    if (thuoc(c, a) || thuoc(c, b)) return true;
    if (thuoc(a, c) && thuoc(b, c)){
        a = find_par(a, c);
        b = find_par(b, c);
        if (a == b) return true;
        if (low[a] < num[c] && low[b] < num[c]) return true;
        return false;
    }
    if (thuoc(a, c) || thuoc(b, c)){
        if (thuoc(b, c)) swap(a, b);
        a = find_par(a, c);
        if (low[a] < num[c]) return true;
        return false;
    }
    return true;
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, m){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    par[1] = -1;
    dfs(1);
    cin >> q;
    while (q--){
        int typ;
        cin >> typ;
        if (typ == 1){
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            if (solve1(a, b, c, d)) cout << "yes\n";
            else cout << "no\n";
        }
        else {
            int a, b, c;
            cin >> a >> b >> c;
            if (solve2(a, b, c)) cout << "yes\n";
            else cout << "no\n";
        }
    }
}
