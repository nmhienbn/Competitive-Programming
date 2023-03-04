#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "freetick"
const int maxn = 5005, INF = 1e9;
using namespace std;

struct dl {
    int u, t, w;
    bool operator < (const dl& x) const {
        return w > x.w;
    }
};

int n, m, f[maxn][2];
vector<pii> g[maxn];
priority_queue<dl> q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, m){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    fi(i, 1, n) fi(j, 0, 1)
        f[i][j] = INF;
    f[1][0] = 0;
    q.push({1, 0, 0});
    while (q.size()){
        int u = q.top().u;
        int t = q.top().t;
        if (f[u][t] < q.top().w){
            q.pop();
            continue;
        }
        if (u == n) break;
        q.pop();
        for (pii vt : g[u]){
            int v = vt.first, w = vt.second;
            if (f[v][t] > f[u][t] + w){
                f[v][t] = f[u][t] + w;
                q.push({v, t, f[v][t]});
            }
            if (t == 0 && f[v][1] > f[u][0]){
                f[v][1] = f[u][0];
                q.push({v, 1, f[v][1]});
            }
        }
    }
    cout << min(f[n][0], f[n][1]);
}
