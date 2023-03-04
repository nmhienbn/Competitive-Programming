#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "superseq"
const int maxn = 101;
const int mod = 666013;

using namespace std;

struct matrix{
    long long a[maxn][maxn] = {};
};

matrix operator * (matrix A, matrix B){
    matrix C;
    fi(i, 0, 100)
        fi(j, 0, 100){
            C.a[i][j] = 0;
            fi(k, 0, 100)
                C.a[i][j] = (C.a[i][j] + A.a[i][k]*B.a[k][j]) % mod;
        }
    return C;
}

matrix binpow(matrix A, long long k){
    if (k == 1) return A;
    matrix C = binpow(A, k/2);
    if (k%2) return A*C*C;
    else return C*C;
}

int n, h, k;
long long a[maxn], res;
matrix A;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> h >> k;
    fi(i, 0, k) a[i] = 1;

    fi(i, 0, h)
        fi(j, max(0, i-k), min(h, i+k))
            A.a[i][j] = 1;

    A = binpow(A, n-2);
    fi(i, 0, 100)
        res = (res + A.a[h][i] * a[i]) % mod;
    cout << res;
}
