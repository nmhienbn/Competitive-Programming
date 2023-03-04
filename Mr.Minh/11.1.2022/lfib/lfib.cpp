#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "lfib"
const int maxn = 8;
using namespace std;

struct matrix {
    ll a[8][8];
};

int nt, a, b, n, k, mod;

matrix operator * (matrix A, matrix B){
    matrix C;
    fi(i, 0, 7) fi(j, 0, 7){
        C.a[i][j] = 0;
        fi(k, 0, 7){
            C.a[i][j] = (C.a[i][j] + A.a[i][k] * B.a[k][j]) % mod;
        }
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

matrix A, res;

void init(){
    A.a[0][0] = A.a[0][1] = A.a[0][2] = 1;
    A.a[1][0] = 1;
    A.a[2][2] = 1;
    A.a[3][2] = A.a[3][3] = A.a[3][5] = 1;
    A.a[4][0] = A.a[4][3] = A.a[4][4] = 1;
    A.a[5][3] = 1;
    A.a[6][0] = A.a[6][1] = A.a[6][2] = A.a[6][6] = 1;
    A.a[7][2] = A.a[7][3] = A.a[7][5] = A.a[7][7] = 1;

    A.a[3][0] = A.a[3][1] = A.a[3][4] = 2;
    A.a[7][0] = A.a[7][1] = A.a[7][4] = 2;
}

void reset(){
    fi(i, 0, 7) fi(j, 0, 7){
        res.a[i][j] = 0;
    }
    res.a[0][0] = b;
    res.a[1][0] = a;
    res.a[2][0] = 1;
    res.a[3][0] = 1ll * b * b % mod;
    res.a[4][0] = 1ll * a * b % mod;
    res.a[5][0] = 1ll * a * a % mod;
    res.a[6][0] = (a + b) % mod;
    res.a[7][0] = (res.a[3][0] + res.a[5][0]) % mod;
}

bool except(){
    if (n == 0){
        cout << "0\n";
        return true;
    }
    if (n == 1){
        if (k == 1) cout << a << '\n';
        else cout << a + b << '\n';
        return true;
    }
    if (n == 2){
        if (k == 1) cout << 1ll * a * a << '\n';
        else cout << 1ll * a * a + 1ll * b * b << '\n';
        return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> nt;
    init();
    while (nt--){
        cin >> a >> b >> n >> k >> mod;
        if (except()) continue;
        reset();
        res = binpow(A, n - 2) * res;
        if (k == 1) cout << res.a[6][0] << '\n';
        else cout << res.a[7][0] << '\n';
    }
}
