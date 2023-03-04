#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "c11seq4"
using namespace std;

ll n, mod;
ll odd, even;

void add(ll& x, ll y){
    x += y;
    if (x >= mod) x -= mod;
}

ll nhan(ll a, ll b){
    ll ans = 0;
    while (b > 0){
        (ans += a * (b % 10)) %= mod;
        b /= 10;
        (a *= 10) %= mod;
    }
    return ans;
}

struct matrix{
    ll a[3][3];
    friend matrix operator * (matrix A, matrix B){
        matrix C;
        fi(i, 0, 2) fi(j, 0, 2){
            C.a[i][j] = 0;
            fi(k, 0, 2){
                add(C.a[i][j], nhan(A.a[i][k], B.a[k][j]));
            }
        }
        return C;
    }
    friend matrix binpow(matrix A, ll k){
        matrix ans = A;
        while (k > 0){
            if (k & 1) ans = ans * A;
            A = A * A;
            k >>= 1;
        }
        return ans;
    }
};

matrix A, res;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> mod;
    even = (n >> 1) + 1;
    odd = n - (n >> 1);
    A.a[0][0] = (even - 1) % mod;
    A.a[1][1] = (odd - 1);
    A.a[0][1] = even % mod;
    A.a[1][0] = odd % mod;
    A.a[2][1] = A.a[2][2] = 1;
    res = binpow(A, n);
    cout << res.a[2][0];
}
