#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "holes"
const int maxn = 505, maxrp = 1e4;

using namespace std;

int ntest, n, m, w, d[maxn];
vector<pii> g[maxn];

void init(){
    cin >> n >> m >> w;
    fi(i, 1, n) g[i].clear();
    fi(i, 1, m){
        int u, v, t;
        cin >> u >> v >> t;
        g[u].pb({v, t});
        g[v].pb({u, t});
    }
    fi(i, 1, w){
        int u, v, t;
        cin >> u >> v >> t;
        g[u].pb({v, -t});
    }
    d[1] = 0;
    fi(i, 2, n) d[i] = 1e9;
}

priority_queue<pii, vector<pii>, greater<pii>> q;

bool Dijkstra(){
    int cnt = 0;
    while (q.size()) q.pop();
    q.push({0, 1});
    while (q.size()){
        int u = q.top().second;
        q.pop();
        cnt++;
        if (cnt > maxrp) return false;
        for (auto vt : g[u]){
            int v = vt.first, t = vt.second;
            if (d[v] > d[u] + t){
                d[v] = d[u] + t;
                q.push({d[v], v});
            }
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);

    cin >> ntest;
    while (ntest--){
        init();
        if (Dijkstra()) cout << "NO\n";
        else cout << "YES\n";
    }
}
