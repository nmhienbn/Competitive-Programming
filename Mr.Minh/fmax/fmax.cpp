#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "fmax"
const int maxn = 105;

using namespace std;

int n, m, a[maxn][maxn], b[maxn][maxn], res, c[maxn][maxn];
int ngg[maxn][maxn][maxn], doc[maxn][maxn][maxn];
int sum, pre;

void minimize(int& x, int y){
    if (x > y) x = y;
}

void maximize(int& x, int y){
    if (x < y) x = y;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> m >> n;
    fi(i, 1, m) fi(j, 1, n){
        cin >> a[i][j];
        b[i][j] = a[i][j] + b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
    }
    fi(i, 1, m) fid(j, n, 1){
        c[i][j] = a[i][j] + c[i - 1][j] + c[i][j + 1] - c[i - 1][j + 1];
    }
    fi(i, 1, m){
        fi(j, i, m){
            sum = 0, pre = 0;
            fid(k, n, 1){
                sum += c[j][k] - c[i - 1][k];
                ngg[i][j][k] = sum - pre;
                minimize(pre, sum);
            }
        }
        fi(j, i + 1, m){
            fi(k, 1, n){
                maximize(ngg[i][j][k], ngg[i][j - 1][k]);
            }
        }
    }
    fi(i, 1, m){
        fi(j, i, m){
            sum = 0, pre = 0;
            fi(k, 1, n){
                sum = b[j][k] - b[i - 1][k];
                doc[i][j][k] = sum - pre;
                minimize(pre, sum);
            }
        }
    }
    fi(i, 1, n - 1){
        fi(j, 1, m){
            fi(k, j + 2, m){
                fi(t, k + 1, m){
                    maximize(res, doc[j][t][i] + ngg[j][k - 2][i + 1] + ngg[k][t - 1][i + 1]);
                }
            }
        }
    }
    cout << res;
}
