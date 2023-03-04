#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "hseq"
const int maxn = 205, INF = 1e9;
using namespace std;

int n, m, nt, a[maxn], f[maxn][maxn], g[maxn][maxn];
int b[maxn];

void reset(){
    fi(i, 1, n) fi(j, 1, n) f[i][j] = INF;
    fi(i, 1, n) fi(j, 0, m) g[i][j] = INF;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> nt;
    while (nt--){
        cin >> n >> m;
        fi(i, 1, n) cin >> a[i];

        reset();
        fi(i, 1, n){
            for (int j = i + 2; j <= n; j += 2){
                int tt = (i + j) >> 1;
                int cnt = 0;
                fi(k, i, j) b[++cnt] = a[k] + abs(tt - k);
                sort(b + 1, b + cnt + 1);
                int dem = 1, ans = 1;
                fi(k, 2, cnt){
                    if (b[k] != b[k - 1]) dem = 1;
                    else {
                        dem++;
                        ans = max(ans, dem);
                    }
                }
                f[i][j] = j - i + 1 - ans;
            }
        }
        fi(i, 1, n){
            for (int j = i + 2; j <= n; j += 2){
                fi(k, 1, m){
                    g[j][k] = min(g[j][k], g[i - 1][k - 1] + f[i][j]);
                }
            }
        }
        cout << g[n][m] << '\n';
    }
}
