#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pli pair<ll,int>
#define pb push_back
#define ll long long
#define Irelia "metro"
const int maxn = 1e5 + 5;
const ll INF = 1e18;
using namespace std;

struct dl {
    int u, v, w;
};

int n, m, st, fn, delta;
dl E[maxn];
vector<int> g[maxn];
ll f[maxn];
priority_queue<pli, vector<pli>, greater<pli>> q;

void minimize(int v, ll s){
    if (f[v] > s){
        f[v] = s;
        q.push({f[v], v});
    }
}

void Dijkstra(){
    f[st] = 0;
    q.push({0, st});
    while (q.size()){
        int u = q.top().second;
        if (f[u] < q.top().first){
            q.pop();
            continue;
        }
        if (u == fn){
            cout << f[fn];
            exit(0);
        }
        q.pop();
        for (int i : g[u]){
            int v = E[i].v, w = E[i].w;
            if (u != st) w += i;
            if (v != fn) w += delta * i;
            minimize(v, f[u] + w);
        }
    }
    cout << -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m >> st >> fn >> delta;
    fi(i, 1, m){
        int u, v, w;
        cin >> u >> v >> w;
        E[i] = {u, v, w};
        g[u].pb(i);
    }
    fi(i, 1, n) f[i] = INF;
    Dijkstra();
}
