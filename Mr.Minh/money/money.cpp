#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "money"
const int maxn = 5005, INF = 2e9;

using namespace std;

struct dl {
    int u, t, w;
    bool operator < (const dl& x) const {
        return w > x.w;
    }
};

int n, m, k, st, fn, a[maxn];
vector<pii> g[maxn];
int L[maxn][2];
priority_queue<dl> q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m >> k >> st >> fn;
    fi(i, 1, k){
        int u, v;
        cin >> u >> v;
        a[u] = v;
    }
    fi(i, 1, m){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    fi(i, 1, n) fi(j, 0, 1) L[i][j] = INF;
    L[st][0] = 0;
    q.push({st, 0, 0});
    if (a[st] > 0){
        L[st][1] = a[st];
        q.push({st, 1, L[st][1]});
    }
    while (q.size()){
        int u = q.top().u, t = q.top().t;
        if (L[u][t] < q.top().w){
            q.pop();
            continue;
        }
        if (u == fn && t) break;
        q.pop();
        for (pii vt : g[u]){
            int v = vt.first, w = vt.second;
            if (L[v][t] > L[u][t] + w){
                L[v][t] = L[u][t] + w;
                q.push({v, t, L[v][t]});
            }
            if (t == 0 && a[v] > 0 && L[v][1] > L[u][0] + w + a[v]){
                L[v][1] = L[u][0] + w + a[v];
                q.push({v, 1, L[v][1]});
            }
        }
    }
    cout << L[fn][1];
}
