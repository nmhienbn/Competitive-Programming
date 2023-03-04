#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "roadblocks"
const int maxn = 5005;
using namespace std;


int n, m, d[maxn][2];
vector<pii> g[maxn];
priority_queue<pii, vector<pii>, greater<pii>> q;

void Dijkstra(){
    fi(i, 1, n) d[i][0] = d[i][1] = 1e9;
    d[1][0] = 0;
    q.push({0, 1});
    while (q.size()){
        int u = q.top().second, l = q.top().first;
        q.pop();
        if (l > d[u][1]) continue;
        for (auto vt : g[u]){
            int v = vt.first, w = vt.second;
            if (d[v][0] > l + w){
                d[v][1] = d[v][0];
                d[v][0] = l+w;
                q.push({d[v][0], v});
            }
            else if (d[v][1] > l + w && l + w > d[v][0]){
                d[v][1] = l+w;
                q.push({d[v][1], v});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, m){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    Dijkstra();
    cout << d[n][1];
}
