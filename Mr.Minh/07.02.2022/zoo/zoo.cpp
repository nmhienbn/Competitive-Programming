#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define maximize(x,y) x = x < y ? y : x
#define pb push_back
#define ll long long
#define Irelia "zoo"
const int maxn = 10005;
using namespace std;

int n, m, res;
int a[maxn][40], f[maxn][40];
int sca[6], lov[6];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    fi(rep, 1, m){
        int e, u, v;
        cin >> e >> u >> v;
        fi(j, 0, 4) lov[j] = sca[j] = 0;
        fi(j, 1, u){
            int x;
            cin >> x;
            sca[(x + n - e) % n] = 1;
        }
        fi(j, 1, v){
            int x;
            cin >> x;
            lov[(x + n - e) % n] = 1;
        }
        fi(x, 0, 31){
            fi(j, 0, 4){
                if (gb(x, 4 - j)){
                    if (lov[j]){
                        a[e][x]++;
                        break;
                    }
                }
                else {
                    if (sca[j]){
                        a[e][x]++;
                        break;
                    }
                }
            }
        }
    }
    fi(i, 0, 15){
        fi(j, 1, n) fi(k, 0, 31) f[j][k] = -1e9;
        f[1][i << 1] = a[1][i << 1];
        f[1][i << 1 | 1] = a[1][i << 1 | 1];
        fi(j, 1, n - 1){
            fi(k, 0, 31){
                int nex = (k & 15) << 1;
                maximize(f[j + 1][nex], f[j][k] + a[j + 1][nex]);
                nex |= 1;
                maximize(f[j + 1][nex], f[j][k] + a[j + 1][nex]);
            }
        }
        fi(k, 0, 31) if ((k & 15) == i) res = max(res, f[n][k]);
    }
    cout << res;
}
