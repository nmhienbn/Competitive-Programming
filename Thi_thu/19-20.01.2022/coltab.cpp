#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "coltab"
const int maxn = 1005;
using namespace std;

int m, n, res;
int a[maxn][maxn], b[maxn][maxn];

int ngg(int row, int l, int r){
    if (l > r) return 0;
    return a[row][r] - a[row][l - 1];
}

int doc(int col, int l, int r){
    if (l > r) return 0;
    return b[r][col] - b[l - 1][col];
}

void except(){
    if (m == 1){
        fi(i, 1, n) fi(j, 1, i){
            res = max(res, ngg(1, j, i));
        }
        cout << res;
        exit(0);
    }
    if (n == 1){
        fi(i, 1, m) fi(j, 1, i){
            res = max(res, doc(1, j, i));
        }
        cout << res;
        exit(0);
    }
}

void sub1(){
    fi(i, 1, m) fi(j, 1, i - 1){
        fi(u, 1, n) fi(v, 1, u - 1){
            res = max(res, ngg(i, v, u) + ngg(j, v, u)
            + doc(u, j + 1, i - 1) + doc(v, j + 1, i - 1));
        }
    }
    cout << res;
    exit(0);
}

void sub2(){
    fi(i, 1, m) fi(j, 1, i - 1){
        int maxs = 0;
        fi(k, 1, n){
            res = max(res, maxs + a[i][k] + a[j][k] + doc(k, j + 1, i - 1));
            maxs = max(maxs, doc(k, j, i) - a[i][k] - a[j][k]);
        }
    }
    cout << res;
    exit(0);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> m >> n;
    fi(i, 1, m) fi(j, 1, n){
        bool x;
        cin >> x;
        a[i][j] = a[i][j - 1] + x;
        b[i][j] = b[i - 1][j] + x;
    }
    except();
    if (max(m, n) <= 50) sub1();
    sub2();
}
