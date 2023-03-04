#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "dhfrbus"
const int maxn = 1e5 + 5;
using namespace std;

struct dl {
    ll w;
    int u, t;
    bool operator < (const dl & x) const {
        return w > x.w;
    }
};

int n, m, k, s, t;
ll f[maxn][6];
vector<pii> g[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m >> k >> s >> t;
    fi(i, 1, m){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    priority_queue<dl> q;
    fi(i, 1, n) fi(j, 0, 5) f[i][j] = 1e18;
    f[s][0] = 0;
    q.push({0, s, 0});
    while (q.size()){
        int u = q.top().u, tt = q.top().t;
        if (q.top().w > f[u][tt]){
            q.pop();
            continue;
        }
        q.pop();
        for (pii vt : g[u]){
            int v = vt.first, w = vt.second;
            if (f[v][tt] > f[u][tt] + w){
                f[v][tt] = f[u][tt] + w;
                q.push({f[v][tt], v, tt});
            }
            if (tt < k && f[v][tt + 1] > f[u][tt]){
                f[v][tt + 1] = f[u][tt];
                q.push({f[v][tt + 1], v, tt + 1});
            }
        }
    }
    cout << *min_element(f[t], f[t] + k + 1);
}
