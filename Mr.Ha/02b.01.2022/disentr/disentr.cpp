#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "disentr"
const int maxn = 1005, INF = 1e8;
using namespace std;

int n, m, st, fn, bd, C, tg;
int vt[maxn], f[maxn];
bool kt[maxn];
int b[maxn][maxn], tblock[maxn][maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, n) fi(j, 1, n) b[i][j] = tblock[i][j] = INF;
    cin >> st >> fn >> bd >> C;
    fi(i, 1, C) cin >> vt[i];
    while (m--){
        int u, v, w;
        cin >> u >> v >> w;
        b[u][v] = b[v][u] = w;
    }
    fi(i, 2, C){
        tblock[vt[i - 1]][vt[i]] = tblock[vt[i]][vt[i - 1]] = tg;
        tg += b[vt[i-1]][vt[i]];
    }
    fi(i, 0, n) f[i] = INF;
    f[st] = bd;
    fi(i, 1, n){
        int m = 0;
        fi(j, 1, n)
            if (!kt[j] && f[j] < f[m])
                m = j;
        kt[m] = 1;
        if (m == fn) break;
        fi(j, 1, n){
            if (f[m] < tblock[j][m]){
                f[j] = min(f[j], f[m] + b[j][m]);
            }
            else {
                f[j] = min(f[j], max(tblock[j][m] + b[j][m], f[m]) + b[j][m]);
            }
        }
    }
    cout << f[fn] - f[st];
}
