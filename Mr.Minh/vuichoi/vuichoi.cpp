#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "vuichoi"
const int maxn = 505,
        doc[4] = {-1, 1, 0, 0},
        ngg[4] = {0, 0, -1, 1},
        ycu[4] = {3, 5, 6, 7};
using namespace std;

struct dl {
    int u, v, tt;
    ll w;
    bool operator < (const dl& x) const {
        return w > x.w;
    }
};

int n, m, a[maxn][maxn];
ll L[maxn][maxn][8], res = 1e18;
int kt[maxn][maxn];

void Dijkstra(int x, int y){
    priority_queue<dl> q;
    fi(i, 1, m) fi(j, 1, n) fi(t, 0, 7) L[i][j][t] = 1e18;
    L[x][y][kt[x][y]] = a[x][y];
    q.push({x, y, kt[x][y], a[x][y]});
    while (q.size()){
        int u = q.top().u, v = q.top().v, t = q.top().tt;
        q.pop();
        fi(i, 0, 3){
            int uu = u + doc[i], vv = v + ngg[i], tt = t | kt[uu][vv];
            if (a[uu][vv] && L[uu][vv][tt] > L[u][v][t] + a[uu][vv]){
                L[uu][vv][tt] = L[u][v][t] + a[uu][vv];
                q.push({uu, vv, tt, L[uu][vv][tt]});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> m >> n;
    fi(i, 0, 2){
        int x, y;
        cin >> x >> y;
        kt[x][y] = 1 << i;
    }
    fi(i, 1, m){
        fi(j, 1, n){
            cin >> a[i][j];
        }
    }
    Dijkstra(1, 1);
    fi(i, 0, 3){
        res = min(res, L[m][n][ycu[i]]);
    }
    cout << res;
}
