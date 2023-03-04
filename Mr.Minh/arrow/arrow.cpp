#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "arrow"
const int maxn = 105;

using namespace std;

int n, m, res, L[maxn], cnt;
char a[maxn][maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> m >> n;
    fi(i, 1, m) fi(j, 1, n) cin >> a[i][j];
    fi(i, 1, m){
        int u = 1, v = 0;
        fi(j, 1, n + 1){
            if (a[i][j] != '<' && a[i][j] != '>'){
                res += (v - u + 1) / 2;
                L[0] = L[1] = 0;
                L[2] = (a[i][u] != '>') + (a[i][u + 1] != '<');
                fi(k, u + 2, v){
                    if ((k - u + 1) % 2 == 0)
                        L[k - u + 1] = L[k - u - 1] + (a[i][k - 1] != '>') + (a[i][k] != '<');
                    else
                        L[k - u + 1] = min(L[k - u - 1], L[k - u - 2]) + (a[i][k - 1] != '>') + (a[i][k] != '<');
                }
                if ((v - u + 1) % 2 == 0) cnt += L[v - u + 1];
                else cnt += min(L[v - u + 1], L[v - u]);
                u = j + 1, v = j;
            }
            else {
                v++;
            }
        }
        //cout << cnt << '\n';
    }
    fi(j, 1, n){
        int u = 1, v = 0;
        fi(i, 1, m + 1){
            if (a[i][j] != '^' && a[i][j] != 'v'){
                res += (v - u + 1) / 2;
                L[0] = L[1] = 0;
                L[2] = (a[u][j] != 'v') + (a[u + 1][j] != '^');
                fi(k, u + 2, v){
                    if ((k - u + 1) % 2 == 0)
                        L[k - u + 1] = L[k - u - 1] + (a[k - 1][j] != 'v') + (a[k][j] != '^');
                    else
                        L[k - u + 1] = min(L[k - u - 1], L[k - u - 2]) + (a[k - 1][j] != 'v') + (a[k][j] != '^');
                }
                if ((v - u + 1) % 2 == 0) cnt += L[v - u + 1];
                else cnt += min(L[v - u + 1], L[v - u]);
                u = i + 1, v = i;
            }
            else {
                v++;
            }
        }
    }
    cout << res << ' ' << cnt;
}
