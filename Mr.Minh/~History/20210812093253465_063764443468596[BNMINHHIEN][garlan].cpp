#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "garlan"
const int maxn = 0;

using namespace std;

int n, m, L[20][20], dp[(1 << 15) + 5][20], res = 1e9;
string s[20];

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> m;
    fi(i, 0, n) s[0][i] = '0';
    fi(i, 1, m){
        cin >> s[i];
    }
    m++;
    fi(i, 0, m-1){
        fi(j, i+1, m-1){
            fi(t, 0, n-1){
                if (s[i][t] != s[j][t]){
                    L[i][j]++;
                    L[j][i]++;
                }
            }
        }
    }
    memset(dp, 60, sizeof(dp));
    dp[0][0] = 0;
    fi(i, 0, m-1) dp[1 << i][i] = L[i][0];
    fi(x, 1, (1 << m) - 1){
        fi(i, 0, m-1){
            if ((x >> i)&1){
                fi(j, 0, m-1){
                    if (!((x >> j)&1)){
                        dp[x | (1 << j)][j] = min(dp[x | (1 << j)][j], dp[x][i] + L[j][i]);
                    }
                }
            }
            //cout << dp[x][i] << ' ';
        }
        //cout << '\n';
    }
    fi(i, 1, m-1){
        res = min(res, dp[(1 << m) - 1][i]);
    }
    cout << res;
}
