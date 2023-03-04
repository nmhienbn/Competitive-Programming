#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "d13r6path"
const int maxn = 5005, maxm = 10;
using namespace std;

int n, m, q;
ll f[maxm][maxn], b[maxm][maxn], a[maxm][maxn];

ll get(int i, int u, int v){
    return b[max(u, v)][i] - b[min(u, v) - 1][i];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> m >> n;
    fi(i, 1, m) fi(j, 1, n) cin >> a[i][j];
    fi(i, 1, m) a[i][0] = 1e9;
    fi(i, 1, m) fi(j, 0, n){
        b[i][j] = b[i - 1][j] + a[i][j];
    }
    cin >> q;
    fi(rep, 1, q){
        int dx, dy, sx, sy;
        cin >> dx >> dy >> sx >> sy;
        if (dy > sy) swap(dx, sx), swap(dy, sy);
        fi(i, 1, m) f[i][dy - 1] = 1e10;
        f[dx][dy - 1] = 0;
        fi(i, dy, sy){
            fi(j, 1, m){
                f[j][i] = 1e10;
                fi(k, 1, m){
                    f[j][i] = min(f[j][i], f[k][i - 1] + min(get(i - 1, j, k) + a[j][i], get(i, j, k)));
                }
                cout << f[i][j] << ' ';
            }
            cout << endl;
        }
        cout << f[sx][sy] << '\n';
    }

}
