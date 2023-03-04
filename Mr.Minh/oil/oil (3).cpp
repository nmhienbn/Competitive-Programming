#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "oil"
const int maxn = 1005;

using namespace std;

int m, n, k, a[maxn][maxn], res;
int f[5][maxn][maxn], g[3][maxn];

void maximize(int& x, int y){
    if (x < y) x = y;
}

int get(int i, int j){
    return a[i][j] + a[i - k][j - k] - a[i][j - k] - a[i - k][j];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> m >> n >> k;
    fi(i, 1, m) fi(j, 1, n){
        cin >> a[i][j];
        a[i][j] = a[i][j] + a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
    }
    fi(i, k, m) fi(j, k, n){
        f[1][i][j] = max({f[1][i - 1][j], f[1][i][j - 1], get(i, j)});
    }
    fi(i, k, m) fid(j, n - k + 1, 1){
        f[2][i][j] = max({f[2][i - 1][j], f[2][i][j + 1], get(i, j + k - 1)});
    }
    fid(i, m - k + 1, 1) fi(j, k, n){
        f[4][i][j] = max({f[4][i + 1][j], f[4][i][j - 1], get(i + k - 1, j)});
    }
    fid(i, m - k + 1, 1) fid(j, n - k + 1, 1){
        f[3][i][j] = max({f[3][i + 1][j], f[3][i][j + 1], get(i + k - 1, j + k - 1)});
    }
    fi(i, k, m){
        fi(j, k, n){
            maximize(g[1][j], get(i, j));
            maximize(g[2][i], get(i, j));
        }
    }
    fi(i, 1, m) fi(j, 1, n){
        maximize(res, f[1][i][j] + f[4][i + 1][j] + f[2][m][j + 1]);
        maximize(res, f[1][i][j] + f[2][i][j + 1] + f[4][i + 1][n]);
        maximize(res, f[2][i][j] + f[3][i + 1][j] + f[1][m][j - 1]);
        maximize(res, f[4][i][j] + f[3][i][j + 1] + f[1][i - 1][n]);
    }
    fi(i, k, n - k * 2){
        maximize(res, f[1][m][i] + g[1][i + k] + f[2][m][i + k + 1]);
    }
    fi(i, k, m - k * 2){
        maximize(res, f[1][i][n] + g[2][i + k] + f[4][i + k + 1][n]);
    }
    //cout << f[3][7][5] << ' ';
    cout << res;
}
