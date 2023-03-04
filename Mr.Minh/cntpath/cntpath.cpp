#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "cntpath"
const int maxn = 200, mod = 1e9 + 7;

using namespace std;

int n, m, q;

struct matrix {
    ll a[maxn][maxn];
};

matrix operator * (matrix A, matrix B){
    matrix C;
    fi(i, 0, n - 1) fi(j, 0, n - 1){
        C.a[i][j] = 0;
        fi(k, 0, n - 1) C.a[i][j] = (C.a[i][j] + A.a[i][k] * B.a[k][j]) % mod;
    }
    return C;
}

matrix binpow(matrix A, ll k){
    if (k == 1) return A;
    bool ok = 1;
    matrix tg;
    while (k > 0){
        if (k & 1){
            if (ok) tg = A, ok = 0;
            else tg = tg * A;
        }
        A = A * A;
        k /= 2;
    }
    return tg;
}

matrix A, res;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m >> q;
    fi(i, 1, m){
        int u, v;
        cin >> u >> v;
        u--, v--;
        A.a[u][v] = 1;
    }
    fi(i, 1, q){
        int s, t, k;
        cin >> s >> t >> k;
        res = binpow(A, k);
        cout << res.a[s-1][t-1] << '\n';
    }
}
