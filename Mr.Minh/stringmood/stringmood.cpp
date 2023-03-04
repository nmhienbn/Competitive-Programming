#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "stringmood"
const int maxn = 2, mod = 1e9 + 7;

using namespace std;

struct matrix {
    ll a[maxn][maxn];
};

matrix operator * (matrix A, matrix B){
    matrix C;
    fi(i, 0, 1) fi(j, 0, 1){
        C.a[i][j] = 0;
        fi(k, 0, 1) C.a[i][j] = (C.a[i][j] + A.a[i][k] * B.a[k][j]) % mod;
    }
    return C;
}

matrix binpow(matrix A, ll k){
    if (k == 1) return A;
    matrix tg = binpow(A, k >> 1);
    tg = tg * tg;
    if (k & 1) return tg * A;
    return tg;
}

ll n;
matrix A;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    A.a[0][0] = 1;
    A.a[0][1] = 1;
    A.a[1][0] = 1;
    A.a[1][1] = 0;
    if (n == 0) cout << 0, exit(0);
    if (n == 1) cout << 1, exit(0);
    A = binpow(A, n - 1);
    cout << A.a[0][0];
}
