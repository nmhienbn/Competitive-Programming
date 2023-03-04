#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define file freopen(Ahri".inp", "r", stdin); freopen(Ahri".out", "w", stdout);
#define Ahri "roadblocks"
const int maxn = 5e3+5;

using namespace std;

int n, m;
ll d[maxn][3];
vector<pii> g[maxn];

void Dijkstra(){
    priority_queue < pii, vector<pii>, greater<pii> > pq;
    pq.push({0, 1});
    while (pq.size()){
        int u = pq.top().second, l = pq.top().first;
        pq.pop();
        if (l > d[u][2]) continue;
        for (auto vt : g[u]){
            int v = vt.first, uv = l+vt.second;
            if (d[v][1] > uv){
                d[v][1] = uv;
            }
            else if (d[v][2] > uv){
                d[v][2] = uv;
            }
            pq.push({uv, v});
        }
    }
}

int main(){
    faster file
    cin >> n >> m;
    fi(i, 1, m){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    fi(i, 1, n) d[i][1] = d[i][2] = 1e18;
    d[1][1] = 0;
    Dijkstra();
    cout << d[n][2];
}
