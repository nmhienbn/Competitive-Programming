#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "fen"
const int maxn = 55, INF = 1e9,
            ngg[4] = {-1, 0, 0, 1},
            doc[4] = {0, -1, 1, 0};
using namespace std;

struct dl {
    int u, v, t;
};

int m, n, a[maxn][maxn], f[maxn][maxn][4];
queue<dl> q;

bool check(int x, int y){
    return (1 <= x && x <= m && 1 <= y && y <= n);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> m >> n;
    fi(i, 1, m) fi(j, 1, n){
        cin >> a[i][j];
        fi(k, 0, 3) f[i][j][k] = INF;
    }
    f[m][1][3] = 0;
    q.push({m, 1, 3});
    while (q.size()){
        dl top = q.front();
        int u = top.u;
        int v = top.v;
        int t = top.t;
        q.pop();
        if (u == 1 && v == n){
            cout << f[u][v][t];
            exit(0);
        }
        int w = (t + 3) % 4;
        if (w && f[u][v][w] > f[u][v][t] + 1){
            f[u][v][w] = f[u][v][t] + 1;
            q.push({u, v, w});
        }
        fi(i, 0, 3){
            int x = u + ngg[i];
            int y = v + doc[i];
            int w = (a[x][y] - f[u][v][t] % 4 + 3) % 4;
            if (check(x, y) && w && f[x][y][w] > f[u][v][t] + 1){
                f[x][y][w] = f[u][v][t] + 1;
                q.push({x, y, w});
            }
        }
    }
}
