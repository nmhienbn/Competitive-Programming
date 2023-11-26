#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define NunuAndWillump "atcoder_dp_r"
const int maxn = 50, mod = 1e9+7;

using namespace std;

int n;
ll k;

struct matrix {
    ll a[50][50];
};

matrix operator * (matrix A, matrix B){
    matrix C;
    fi(i, 0, n-1){
        fi(j, 0, n-1){
            C.a[i][j] = 0;
            fi(k, 0, n-1){
                C.a[i][j] = (C.a[i][j] + A.a[i][k] * B.a[k][j]) % mod;
            }
        }
    }
    return C;
}

matrix mu(matrix A, ll k){
    if (k == 1) return A;
    auto tg = mu(A, k >> 1);
    tg = tg * tg;
    if (k & 1) tg = tg * A;
    return tg;
}
matrix A;

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n >> k;
    fi(i, 0, n-1){
        fi(j, 0, n-1){
            cin >> A.a[i][j];
        }
    }
    A = mu(A, k);
    ll res = 0;
    fi(i, 0, n-1) fi(j, 0, n-1) res = (res + A.a[i][j]) % mod;
    cout << res;
}
