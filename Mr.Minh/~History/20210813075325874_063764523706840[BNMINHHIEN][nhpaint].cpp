#include <bits/stdc++.h>
#define fi(i,a,b) for(int i=a; i<=b; i++)
#define fid(i,a,b) for(int i=a; i>=b; i--)
#define fir first
#define se second
#define bit(i,j) ((i>>j)&1)
#define bit2(i) (1<<(i-1))
#define ll long long
#define pii pair<int,int>

#define maxn 10005
#define maxm 1000006
#define MOD
#define MinhDz "NHPAINT"

using namespace std;

int m, n, a[16][16], L[16][16], T[16], dp[1 << 16][16], res = 1e9;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(MinhDz".inp","r",stdin);
    freopen(MinhDz".out","w",stdout);
    cin >> m >> n;
    fi(i, 0, m-1)
        fi(j, 0, n-1) cin >> a[i][j];
    fi(i, 0, n-1){
        fi(j, i+1, n-1){
            fi(t, 0, m-1){
                if (a[i][t] != a[j][t]){
                    L[i][j]++;
                    L[j][i]++;
                }
            }
        }
        fi(t, 0, m-1){
            if (a[i][t] != 0){
                T[i]++;
            }
        }
    }
    memset(dp, 60, sizeof(dp));
    fi(i, 0, n-1) dp[1 << i][i] = T[i];
    fi(x, 1, (1 << n) - 1){
        fi(i, 0, n-1){
            if ((x >> i) & 1){
                fi(j, 0, n-1){
                    if (!((x >> j)&1)){
                        dp[x | (1 << j)][j] = min(dp[x | (1 << j)][j], dp[x][i] + L[i][j]);
                        if (abs(j-i) == 1){
                            dp[x | (1 << j)][j] = min(dp[x | (1 << j)][j], dp[x][i] + T[j]);
                        }
                    }
                }
            }
        }
    }
    fi(i, 0, n-1){
        res = min(res, dp[(1 << n) -1][i]);
    }
    cout << res;
}
