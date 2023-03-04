#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "func"
const int maxn = 0;
using namespace std;

struct matrix {
    ll a[2][2];
};

ll k, m, r, p, q;

ll nhan(ll a, ll b){
    if (a <= 1e9 && b <= 1e9) return a*b;
    ll res = 0;
    while (a > 0){
        int now = a%10;
        res = (res + b*now) % m;
        b = b * 10 % m;
        a /= 10;
    }
    return res;
}

matrix operator * (matrix a, matrix b){
    matrix c;
    fi(i, 0, 1) fi(j, 0, 1){
        c.a[i][j] = 0;
        fi(k, 0, 1) c.a[i][j] = (c.a[i][j] + nhan(a.a[i][k], b.a[k][j])) % m;
    }
    return c;
}

matrix mu(matrix A, ll k){
    matrix res = A;
    int n = log2(k);
    fid(i, n-1, 0){
        res = res * res;
        if ((k >> i) & 1) res = res * A;
    }
    return res;
}

matrix A;

void xuli(){
    A.a[0][0] = 0;
    A.a[0][1] = 1;
    A.a[1][0] = 1;
    A.a[1][1] = r;
    if (k == 1){
        cout << p % m << ' ' << q % m << '\n';
    }
    else {
        A = mu(A, k-1);
        cout << (A.a[0][0] * p + A.a[0][1] * q) % m << ' '
            << (A.a[1][0] * p + A.a[1][1] * q) % m << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    while (cin >> k >> r >> p >> q >> m){
        ll gcd = __gcd(p, q);
        p /= gcd;
        q /= gcd;
        xuli();
    }
}
