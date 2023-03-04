#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "lights"
const int maxn = 16;

using namespace std;

int n, a[maxn][maxn], dp[1 << 16][16], res = 1e9;

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
    memset(dp, 60, sizeof(dp));
    fi(i, 0, n-1) dp[1 << i][i] = 0;
    fi(x, 1, (1 << n) - 1){
        fi(i, 0, n-1){
            if ((x >> i) & 1){
                fi(j, 0, n-1){
                    if (!((x >> j) & 1)){
                        dp[x | (1 << j)][j] = min(dp[x | (1 << j)][j], dp[x][i] + a[i][j]);
                    }
                }
            }
        }
    }
    fi(i, 0, n-1){
        res = min(res, dp[(1 << n) - 1][i]);
    }
    cout << res;
}
