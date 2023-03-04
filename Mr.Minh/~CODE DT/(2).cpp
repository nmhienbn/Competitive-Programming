#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia ""
const int maxn = 2e5+5, mod = 1e9 + 7;

using namespace std;

int n, res[maxn], res2[maxn];
vector<int> g[maxn];

int binpow(int a, int k){
    if (k == 1) return a;
    int tg = binpow(a, k >> 1);
    if (k & 1) return (1ll * tg * tg % mod) * a % mod;
    return 1ll * tg * tg % mod;
}

void dfs(int u, int p){
    res[u] = 1;
    for (int v : g[u]){
        if (v == p) continue;
        dfs(v, u);
        res[u] = 1ll * res[u] * (res[v] + 1) % mod;
    }
}

void dfs2(int u, int p){
    for (int v : g[u]){
        if (v == p) continue;
        res2[v] = (1ll * (res2[u] + 1) * res[u] % mod) * binpow(res[v] + 1, mod - 2) % mod;
        dfs2(v, u);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
//    freopen(Irelia".inp", "r", stdin);
//    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 2, n){
        int p;
        cin >> p;
        g[p].pb(i);
    }
    dfs(1, 0);
    dfs2(1, 0);
    fi(i, 1, n) cout << res[i] << ' '; cout << endl;
    fi(i, 1, n) cout << res2[i] << ' ' ; cout << endl;
    fi(i, 1, n) cout << 1ll * res[i] * (res2[i] + 1) % mod << ' ';
}
