#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "banhkhuc"
const int maxn = 505;
using namespace std;

int n, k;
int a[21];
int f[maxn][maxn];
int dp[1 << 20][20], res = 2e9;

void minimize(int& x, int y){
    if (x > y) x = y;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> k;
    fi(i, 1, n) fi(j, 1, n) cin >> f[i][j];
    fi(i, 0, k - 1) cin >> a[i];
    fi(k, 1, n){
        fi(i, 1, n){
            fi(j, 1, n){
                minimize(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
    int u = (1 << k) - 1;
    fi(x, 1, u) fi(i, 0, k - 1) dp[x][i] = res;
    fi(i, 0, k - 1) dp[1 << i][i] = f[1][a[i]];
    fi(x, 1, u - 1){
        for (int hi = x; hi > 0; hi -= hi & -hi){
            for (int hj = u ^ x; hj > 0; hj -= hj & -hj){
                int i = __builtin_ctz(hi);
                int j = __builtin_ctz(hj);
                minimize(dp[x | (1 << j)][j], dp[x][i] + f[a[i]][a[j]]);
            }
        }
    }
    fi(i, 0, k - 1) minimize(res, dp[u][i] + f[a[i]][1]);
    cout << res;
}
