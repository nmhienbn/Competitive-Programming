#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "journ"
const int maxn = 105;
using namespace std;

struct dl {
    int f, s, t, w;
    bool operator < (const dl& x) const {
        return w > x.w;
    }
};

int n, st, fn, k, cnt;
int f[maxn][13][2];
vector<pii> g[2][maxn];
priority_queue<dl> q;
dl pre[maxn][13][2], tmp, luu[1005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> st >> fn >> n >> k;
    fi(i, 1, k){
        int u, v, w;
        cin >> u >> v >> w;
        g[0][v].pb({u, w});
        g[1][u].pb({v, w});
    }
    memset(f, 60, sizeof f);
    f[st][0][1] = 0;
    q.push({st, 0, 1, 0});
    while (q.size()){
        int u = q.top().f, tg = q.top().s, dd = q.top().t;
        int d1 = dd ^ 1;
        int rem = 24 - tg;
        q.pop();
        if (f[u][0][d1] > f[u][tg][dd] + rem){
            f[u][0][d1] = f[u][tg][dd] + rem;
            pre[u][0][d1] = {u, tg, dd, 0};
            q.push({u, 0, d1, f[u][0][d1]});
        }
        for (pii vt : g[d1][u]){
            int v = vt.first, w = vt.second;
            if (f[v][w][d1] > f[u][tg][dd] + w + rem){
                f[v][w][d1] = f[u][tg][dd] + w + rem;
                pre[v][w][d1] = {u, tg, dd, w};
                q.push({v, w, d1, f[v][w][d1]});
            }
        }
        for (pii vt : g[dd][u]){
            int v = vt.first, w = vt.second;
            if (tg + w <= 12 && f[v][tg + w][dd] > f[u][tg][dd] + w){
                f[v][tg + w][dd] = f[u][tg][dd] + w;
                pre[v][tg + w][dd] = {u, tg, dd, w};
                q.push({v, tg + w, dd, f[v][tg + w][dd]});
            }
        }
    }
    int res = 1e9, x = fn, y, z;
    fi(i, 0, 12) fi(j, 0, 1){
        if (res > f[fn][i][j]){
            res = f[fn][i][j];
            y = i;
            z = j;
        }
    }
    while (x != st || z != 1){
        luu[++cnt] = {x, y, z, pre[x][y][z].w};
        tmp = pre[x][y][z];
        x = tmp.f;
        y = tmp.s;
        z = tmp.t;
    }
    luu[++cnt] = {x, y, z, pre[x][y][z].w};
    int day = 1;
    fid(i, cnt - 1, 1){
        if (luu[i].t != luu[i + 1].t) day++;
        if (luu[i].f != luu[i + 1].f){
            cout << luu[i + 1].f << ' ' << luu[i].f
                << ' ' << day << ' ' << luu[i].w << '\n';
        }
    }
}
