#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "lamp"
const int maxn = 505, ngg[4] = {-1, -1, 1, 1}, doc[4] = {-1, 1, -1, 1};
const char tt[4] = {'\\', '/', '/', '\\'};
using namespace std;

int n, m, dp[maxn][maxn];
char a[maxn][maxn];
pii q[maxn*maxn];

bool kt(int l, int a, int r){
    return l <= a && a <= r;
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, n){
        fi(j, 1, m){
            cin >> a[i][j];
        }
    }
    if ((m+n)&1){
        cout << "NO SOLUTION";
        return 0;
    }
    memset(dp, 60, sizeof(dp));
    dp[1][1] = 0;
    int d = n+1, c = n;
    q[++c] = {1, 1};
    while (d <= c){
        int u = q[d].first, v = q[d++].second;
        fi(i, 0, 3){
            int u1 = u+ngg[i], v1 = v+doc[i];
            int u2 = min(u, u1), v2 = min(v, v1);
            if (kt(1, u1, n+1) && kt(1, v1, m+1)){
                //cout << u1 << ' ' << v1 << '\n';
                if (a[u2][v2] == tt[i]){
                    if (dp[u1][v1] > dp[u][v]){
                        dp[u1][v1] = dp[u][v];
                        q[--d] = {u1, v1};
                    }
                }
                else {
                    if (dp[u1][v1] > dp[u][v]+1){
                        dp[u1][v1] = dp[u][v]+1;
                        q[++c] = {u1, v1};
                    }
                }
            }
        }
    }
    cout << dp[n+1][m+1];
}
