#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "knightpaths"
const int maxn = 65;

using namespace std;

struct matrix {
    unsigned a[maxn][maxn];
};

matrix operator * (matrix A, matrix B){
    matrix C;
    fi(i, 0, 64) fi(j, 0, 64){
        C.a[i][j] = 0;
        fi(k, 0, 64) C.a[i][j] += A.a[i][k] * B.a[k][j];
    }
    return C;
}

matrix binpow(matrix A, int k){
    if (k == 1) return A;
    bool ok = 1;
    matrix res;
    while (k > 0){
        if (k & 1){
            if (ok) res = A, ok = 0;
            else res = res * A;
        }
        A = A * A;
        k /= 2;
    }
    return res;
}

int k;
matrix A;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> k;
    fi(i, 0, 63) fi(j, i + 1, 63){
        int dr = abs(i / 8 - j / 8);
        int dc = abs(i % 8 - j % 8);
        if ((dr == 2 && dc == 1) || (dr == 1 && dc == 2)){
            A.a[i][j] = 1;
            A.a[j][i] = 1;
        }
    }
    fi(i, 0, 64) A.a[64][i] = 1;
    A = binpow(A, k + 1);
    cout << A.a[64][0];
}
