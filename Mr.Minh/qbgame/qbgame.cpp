#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define getbit(x, i) (((x) >> (i)) & 1)
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL);
#define NunuAndWillump "qbgame"
const int maxn = 1e4+5;

using namespace std;

int n, a[maxn][8], maxa;
ll b[1 << 8], c[1 << 8], d[1 << 8];
vector<int> tt;

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n;
    fi(j, 0, 7) fi(i, 1, n) {cin >> a[i][j]; maxa = max(maxa, a[i][j]);}
    int m = (1 << 8) - 1;
    fi(x, 0, m){
        bool kt = 1;
        fi(i, 1, 7){
            if (getbit(x, i) && getbit(x, i-1)){
                kt = 0;
                break;
            }
        }
        if (kt) tt.pb(x);
    }
    fi(i, 1, n){
        fi(x, 1, m){
            fi(j, 0, 7){
                if (getbit(x, j)){
                    b[x] = b[x - (1 << j)] + a[i][j];
                    break;
                }
            }
        }
        fi(x, 0, m) c[x] = -1e18;
        for (auto u : tt){
            for (auto v : tt){
                if ((u&v) == 0){
                    c[u] = max(c[u], d[v] + b[u]);
                }
            }
        }
        for (auto u : tt) d[u] = c[u];
    }
    if (maxa < 0) cout << maxa;
    else cout << *max_element(d, d+256);
}
