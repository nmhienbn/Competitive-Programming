#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "cway2"
const int maxn = 100, mod = 1e9 + 7;

using namespace std;

int n, m, N, st, fn, k, f[maxn], vt[15][15];
vector<int> g[maxn];

struct matrix {
    ll a[maxn][maxn];
};

matrix operator * (matrix A, matrix B){
    matrix C;
    fi(i, 0, N - 1) fi(j, 0, N - 1){
        C.a[i][j] = 0;
        fi(k, 0, N - 1){
            C.a[i][j] = (C.a[i][j] + A.a[i][k] * B.a[k][j]) % mod;
        }
    }
    return C;
}

matrix binpow(matrix A, int k){
    matrix res;
    bool flag = 1;
    while (k > 0){
        if (k & 1){
            if (flag) res = A, flag = 0;
            else res = res * A;
        }
        A = A * A;
        k /= 2;
    }
    return res;
}

matrix A;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    N = n * n;
    fi(i, 1, n) fi(j, 1, n){
        vt[i][j] = (i - 1) * n + j - 1;
    }
    fi(i, 1, m){
        int u, v;
        cin >> u >> v;
        f[vt[u][v]] = f[vt[v][u]] = 1;
        g[u].pb(v);
        g[v].pb(u);
    }
    cin >> st >> fn >> k;
    if (k == 1){
        cout << f[vt[st][fn]];
        exit(0);
    }
    fi(u, 1, n){
        for (int v : g[u]){
            for (int p : g[u]) if (v != p){
                A.a[vt[u][v]][vt[p][u]] = 1;
            }
        }
    }
    A = binpow(A, k - 1);
    ll res = 0;
    for (int u : g[fn]){
        fi(v, 1, n)
            res = (res + A.a[vt[u][fn]][vt[st][v]] * f[vt[st][v]]) % mod;
    }
    cout << res;
}
