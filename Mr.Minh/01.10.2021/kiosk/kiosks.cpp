#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "kiosks"
const int maxn = 1e4+5, mod = 1e9+7;

using namespace std;

int n, k, c[maxn], f[maxn], res;
vector<int> g[maxn];

bool getbit(int x, int i){
    if (i > k) return 0;
    return (x >> i) & 1;
}

int s = 0;
void dfs(int u, int par, int tt){
    f[u] = 1;
    if (getbit(tt, c[u])) f[u] = 0;
    for(int v : g[u]) if (v != par){
        dfs(v, u, tt);
        f[u] = (1ll*f[u]*(f[v] + 1)) % mod;
    }
    res = ((res + f[u] * s) % mod + mod) % mod;
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> k;
    fi(i, 1, n) cin >> c[i], c[i]--;
    fi(i, 2, n){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    fi(tt, 0, (1 << k) - 1){
        if (__builtin_parity(tt)) s = -1;
        else s = 1;
        dfs(1, 0, tt);
    }
    cout << res;
}
