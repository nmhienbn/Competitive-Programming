#include <bits/stdc++.h>
#define fi(i,a,b) for (int i = a, _b = b; i <= _b; i++)
#define fid(i,a,b) for (int i = a, _b = b; i >= _b; i--)
#define gb(x,i) (((x) >> (i)) & 1)
#define minimize(x,y) x = x > y ? y : x
#define pb push_back
#define ll long long
#define Irelia "supman"
const int maxn = 25, INF = 1e9;
using namespace std;

int n, m, k;
int a[maxn], f[maxn][maxn];
int dp[1 << 20][21];

int ceil(int a, int b){
    return a / b + (a % b > 0);
}

int calc(int i, int j){
    if (i == j) return n / 2;
    int x = min((i - j + n) % n, (j - i + n) % n);
    int y1 = ceil(n + 1 - x * 3, 2);
    int y2 = ceil(n - x * 2, 3);
    int ans = 0, z;
                int d1 = kc(a[i], a[j]);
            int d2 = n - d1;
            d1--; d2--;
            int k = d2;
            if (d1 * 2 <= d2) k = d2 - (d2 - 2 * d1) / 2;
            else k = d2 - (d2 - d1) / 3;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m >> k;
    m <<= 1;
    fi(i, 1, m) cin >> a[i];
    fi(i, 1, k){
        int u, v;
        cin >> u >> v;
        f[u][v] = f[v][u] = INF;
    }
    fi(i, 1, m) fi(j, 1, i - 1){
        if (f[i][j] == INF) continue;
        f[i][j] = f[j][i] = calc(a[i], a[j]);
    }
    int u = (1 << m) - 1;
    fi(x, 1, u) fi(i, 0, m - 1) dp[x][i] = INF;
    fi(i, 0, m - 1) dp[1 << i][i] = 0;
    fi(x, 1, u - 1){
        int k = __builtin_parity(x);
        if (k){
            fi(i, 0, m - 1) if (gb(x, i)){
                fi(j, 0, m - 1) if (!gb(x, j)){
                    minimize(dp[x | (1 << j)][j], dp[x][i] + f[i + 1][j + 1]);
                    //cout << x << ' ' << i << ' ' << j << ' ' << dp[x][i] + f[i][j] << ' ';
                }
            }
        }
        else {
            fi(i, 0, m - 1) if (gb(x, i)){
                fi(j, 0, m - 1) if (!gb(x, j)){
                    minimize(dp[x | (1 << j)][j], dp[x][i]);
                }
            }
        }
        //cout << endl;
    }
//    fi(x, 1, u){
//        cout <<  __builtin_parity(x) << ' ';
//        fi(i, 0, m - 1) cout << (dp[x][i] == INF ? -1 : dp[x][i]) << ' ';
//        cout << endl;
//    }
    int ans = INF;
    fi(i, 0, m - 1) minimize(ans, dp[u][i]);
    cout << ans;
    //cin >> n >> m >> k; cout << '\n' << calc(m, k);
}
