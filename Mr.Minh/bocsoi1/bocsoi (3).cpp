#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fig(i, a, b) for(i = (a); i <= b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "bocsoi"
#define lap(i, j)  fig(i[1], 0, j[1]) fig(i[2], 0, j[2])  fig(i[3], 0, j[3])  fig(i[4], 0, j[4]) fig(i[5], 0, j[5])
const int maxn = 31, mod = 111539786;
using namespace std;

int n, a[10][31], b[10], f[31][31][31][31][31], now, mu[10], j[6], k[6], g[6];

void add(int&x, int y){
    x += y;
    if (x >= mod) x -= mod;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        cin >> a[i][0];
        fi(t, 1, 30) {
            if (a[i][t - 1] % 2) a[i][t] = a[i][t - 1] - 1;
            else a[i][t] = a[i][t - 1] / 2;
            if (a[i][t] == 0) {
                j[i] = t;
                break;
            }
        }
    }
    fi(i, 1, n) g[i] = i;
    g[n + 1] = 1;
    f[0][0][0][0][0] = 1;
    lap(k, j){
        int L = f[k[1]][k[2]][k[3]][k[4]][k[5]];
        fi(i, 1, n) if (a[i][k[i]] % 2 && a[g[i + 1]][k[g[i + 1]]] % 2){
            k[i]++;
            k[g[i + 1]]++;
            add(f[k[1]][k[2]][k[3]][k[4]][k[5]], L);
            k[i]--;
            k[g[i + 1]]--;
        }
        int t[6];
        fi(i, 1, n){
            t[i] = 1;
            if (a[i][k[i]] / 2 != a[i][k[i] + t[i]]) t[i]++;
        }
        fi(i, 1, n) if (a[i][k[i]] && a[g[i + 1]][k[g[i+1]]]){
            k[i] += t[i];
            k[g[i + 1]] += t[g[i + 1]];
            add(f[k[1]][k[2]][k[3]][k[4]][k[5]], L);
            k[i] -= t[i];
            k[g[i + 1]] -= t[g[i + 1]];
        }
    }
    cout << f[j[1]][j[2]][j[3]][j[4]][j[5]];
}
