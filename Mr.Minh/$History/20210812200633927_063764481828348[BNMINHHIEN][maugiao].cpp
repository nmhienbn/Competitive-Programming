#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "maugiao"
const int maxn = 25;

using namespace std;

int n, a[maxn][maxn];
ll dp[1<<20][20], res, cnt[1<<20][20], dem;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    fi(i, 0, n-1){
        fi(j, 0, n-1){
            cin >> a[i][j];
        }
    }
    fi(i, 0, n-1) dp[1 << i][i] = a[i][0], cnt[1 << i][i] = 1;
    fi(x, 1, (1 << n) - 1){
        int k = __builtin_popcount(x);
        fi(i, 0, n-1){
            if ((x >> i) & 1){
                fi(j, 0, n-1){
                    if (!((x >> j) & 1)){
                        if (dp[x | (1 << j)][j] < dp[x][i] + a[j][k]){
                            dp[x | (1 << j)][j] = dp[x][i] + a[j][k];
                            cnt[x | (1 << j)][j] = cnt[x][i];
                        }
                        else if (dp[x | (1 << j)][j] == dp[x][i] + a[j][k]){
                            cnt[x | (1 << j)][j] += cnt[x][i];
                        }
                    }
                }
            }
        }
    }
    fi(i, 0, n-1){
        if (res < dp[(1 << n) - 1][i]){
            res = dp[(1 << n) - 1][i];
            dem = cnt[(1 << n) - 1][i];
        }
        else if (res == dp[(1 << n) - 1][i]){
            dem += cnt[(1 << n) - 1][i];
        }
    }
    cout << res << ' ' << dem;
}
