#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "gcdpath"
const int maxn = 3e5+5;
using namespace std;

int sub, n, a[maxn], b[maxn][15], h[maxn], d[maxn][15];
vector<int> g[maxn];
ll res;

void dfs(int u, int par){
    for (int v : g[u]){
        if (v == par) continue;
        b[v][0] = u;
        d[v][0] = a[v];
        fi(i, 1, 12){
            b[v][i] = b[b[v][i-1]][i-1];
            d[v][i] = __gcd(d[b[v][i-1]][i-1], d[v][i-1]);
        }
        h[v] = h[u] + 1;
        dfs(v, u);
    }
}

int LCA(int u, int v){
    if (h[u] < h[v]) swap(u, v);
    int d = h[u] - h[v];
    fid(i, 12, 0) if ((d >> i) & 1){
        u = b[u][i];
    }
    if (u == v) return u;
    fid(i, 12, 0) if (b[u][i] != b[v][i]){
        u = b[u][i];
        v = b[v][i];
    }
    return b[u][0];
}

int cal(int u, int v){
    int lca = LCA(u, v);
    int ans = a[lca];
    int tmp = h[u] - h[lca];
    fid(i, 12, 0) if ((tmp >> i) & 1){
        ans = __gcd(ans, d[u][i]);
        u = b[u][i];
    }
    tmp = h[v] - h[lca];
    fid(i, 12, 0) if ((tmp >> i) & 1){
        ans = __gcd(ans, d[v][i]);
        v = b[v][i];
    }
    return ans;
}

void sub2(){
    fi(i, 1, n){
        fi(j, 1, i-1){
            res += cal(i, j);
        }
    }
    cout << res;
    exit(0);
}

void sub3(){
    map<int, int> mp;
    fi(i, 2, n){
        a[i] = __gcd(a[1], a[i]);
        res += a[i];
        mp[a[i]]++;
    }
    for (pii u : mp){
        res += 1ll * u.second * (u.second - 1) * u.first / 2;
        for (pii v : mp){
            if (v.first < u.first){
                res += 1ll * u.second * v.second * __gcd(u.first, v.first);
            }
            else break;
        }
    }
    cout << res;
    exit(0);
}

map<int, ll> L[maxn];

void dfs4(int u, int par){
    for (auto it : L[par]){
        L[u][__gcd(a[u], it.first)] += it.second;
    }
    for (auto it : L[u]){
        res += 1ll * it.first * it.second;
    }
    L[u][a[u]]++;
    for (int v : g[u]) if (v != par){
        dfs4(v, u);
    }
}

void dfs1(int u, int par){
    for (int v : g[u]){
        if (v == par) continue;
        h[v] = h[u] + 1;
        dfs1(v, u);
    }
}

void sub4(){
    dfs1(1, 0);
    int vt = max_element(h+1, h+n+1) - h;
    dfs4(vt, 0);
    cout << res;
    exit(0);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> sub >> n;
    fi(i, 1, n) cin >> a[i];
    fi(i, 1, n-1){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    if (sub <= 3) dfs(1, 0);
    if (sub <= 2){
        sub2();
    }
    if (sub == 3){
        sub3();
    }
    if (sub == 4){
        sub4();
    }
}
