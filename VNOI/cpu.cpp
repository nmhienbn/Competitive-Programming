#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "cpu"
const int maxn = 25, maxm = 105;
using namespace std;

int n;
string s[maxn];
int f[maxn][maxn], g[maxm][maxm];
int dp[1 << 20];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    n *= 2;
    fi(i, 1, n) cin >> s[i], s[i] = ' ' + s[i];
    g[0][0] = 0;
    fi(i, 1, 100) g[0][i] = g[i][0] = i;
    fi(i, 1, n) fi(j, i + 1, n){
        fi(u, 1, s[i].size() - 1) fi(v, 1, s[j].size() - 1){
            g[u][v] = min(g[u][v - 1], g[u - 1][v]) + 1;
            if (s[i][u] == s[j][v]){
                g[u][v] = min(g[u][v], g[u - 1][v - 1] + 1);
            }
        }
        f[i][j] = f[j][i] = g[s[i].size() - 1][s[j].size() - 1];
    }
    int u = (1 << n) - 1;
    fi(x, 1, u){
        dp[x] = 1e9;
        if (!__builtin_parity(x)){
            fi(i, 0, n - 1) if (gb(x, i))
            fi(j, i + 1, n - 1) if (gb(x, j)){
                dp[x] = min(dp[x], max(dp[x - (1 << i) - (1 << j)], f[i + 1][j + 1]));
            }
        }
    }
    //fi(i, 1, n) {fi(j, 1, n) cout << g[i][j] << ' '; cout << endl;}
    //fi(i, 1, u) cout << dp[i] << ' ';
    cout << dp[u];
}
