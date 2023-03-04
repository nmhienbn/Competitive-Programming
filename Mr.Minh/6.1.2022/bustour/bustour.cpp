#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "bustour"
using namespace std;
const int maxn = 1005, INF = 1e9;

struct dl {
    int u, v, w;
    bool operator < (const dl & x) const {
        return w > x.w;
    }
};

struct bus{
    int u, v, s, c, t;
};

int w, h, sx, sy, dx, dy, n;
vector<bus> g[maxn][maxn];
priority_queue<dl> q;
int f[maxn][maxn], luu[maxn][maxn];

void Dijkstra(){
    fi(i, 1, w) fi(j, 1, h){
        f[i][j] = 1e9;
    }
    f[sx][sy] = 0;
    q.push({sx, sy, 0});
    while (q.size()){
        int i = q.top().u;
        int j = q.top().v;
        if (f[i][j] < q.top().w){
            q.pop();
            continue;
        }
        if (i == dx && j == dy) break;
        q.pop();
        for (auto [u, v, s, c, t] : g[i][j]){
            int w = ((s - f[i][j]) % c + c) % c;
            if (!w && t != luu[i][j]) w += c;
            if (f[u][v] > f[i][j] + w + 1){
                f[u][v] = f[i][j] + w + 1;
                luu[u][v] = t;
                q.push({u, v, f[u][v]});
            }
        }
    }
    cout << f[dx][dy];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> w >> h >> sx >> sy >> dx >> dy >> n;
    fi(i, 1, n) {
        int x1, y1, x2, y2, t;
        cin >> x1 >> y1 >> x2 >> y2 >> t;
        int c = (x2 - x1 + y2 - y1) * 2;
        t = (c - t) % c;
        fi(j, x1, x2 - 1){
            g[j][y1].pb({j + 1, y1, t, c, i});
            t = (t + 1) % c;
        }
        fi(j, y1, y2 - 1){
            g[x2][j].pb({x2, j + 1, t, c, i});
            t = (t + 1) % c;
        }
        fid(j, x2, x1 + 1){
            g[j][y2].pb({j - 1, y2, t, c, i});
            t = (t + 1) % c;
        }
        fid(j, y2, y1 + 1){
            g[x1][j].pb({x1, j - 1, t, c, i});
            t = (t + 1) % c;
        }
    }
    Dijkstra();
}
