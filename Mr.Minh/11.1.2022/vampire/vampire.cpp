#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "vampire"
const int maxn = 1605, maxs = 3605, INF = 1e9;
using namespace std;

struct dl {
    int u, v, w;
    bool operator < (const dl & x) const {
        return w > x.w;
    }
};

int n, m, s;
int f[maxn][maxs];
vector<dl> g[maxn];
priority_queue<dl> q;

void Dijkstra(){
    fi(i, 1, n) fi(j, 0, s){
        f[i][j] = INF;
    }
    f[1][0] = 0;
    q.push({1, 0, 0});
    while (q.size()){
        int u = q.top().u, t = q.top().v;
        if (u == n){
            cout << f[u][t];
            exit(0);
        }
        if (f[u][t] < q.top().w){
            q.pop();
            continue;
        }
        q.pop();
        for (dl vt : g[u]){
            int v = vt.u, w = vt.v, ok = vt.w;
            ok = t + ok * w;
            if (ok > s) continue;
            if (f[v][ok] > f[u][t] + w){
                f[v][ok] = f[u][t] + w;
                q.push({v, ok, f[v][ok]});
            }
        }
    }
    cout << -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> s >> n >> m;
    fi(i, 1, m){
        int u, v, w, t;
        cin >> u >> v >> w >> t;
        u++;
        v++;
        g[u].pb({v, w, t});
        g[v].pb({u, w, t});
    }
    Dijkstra();

}
