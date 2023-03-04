#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "rblock"
const int maxn = 10005, INF = 1e9;
using namespace std;

struct dl {
    int u, v, w;
    int other(const int& x) {
        return u ^ v ^ x;
    }
};

int n, m, bd, res, f[maxn], pre[maxn];
vector<int> g[maxn];
dl a[maxn];
bool cl[maxn];
priority_queue<pii, vector<pii>, greater<pii>> q;

void Dijkstra(int st, int fn){
    while (q.size()) q.pop();
    fi(i, 1, n) f[i] = INF;
    f[st] = 0;
    q.push({0, st});
    while (q.size()){
        int u = q.top().second;
        if (u == fn) return;
        if (f[u] < q.top().first){
            q.pop();
            continue;
        }
        q.pop();
        for (int i : g[u]){
            int v = a[i].other(u), w = a[i].w;
            if (f[v] > f[u] + w){
                f[v] = f[u] + w;
                pre[v] = i;
                q.push({f[v], v});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, m){
        int u, v, w;
        cin >> u >> v >> w;
        a[i] = {u, v, w};
        g[u].pb(i);
        g[v].pb(i);
    }
    Dijkstra(1, n);
    res = bd = f[n];
    int u = n;
    while (u > 1){
        cl[pre[u]] = 1;
        u = a[pre[u]].other(u);
    }
    fi(i, 1, m) if (cl[i]){
        a[i].w *= 2;
        Dijkstra(1, n);
        res = max(res, f[n]);
        a[i].w /= 2;
    }
    cout << res - bd;
}
