#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "tours13"
const int maxn = 1005, INF = 1e9;
using namespace std;

int T, n, m;
vector<int> g[maxn];
int d[maxn][maxn];

int shortest_paths(int v0) {
    d[v0][v0] = 0;
    vector<int> m(n + 1, 2);
    deque<int> q;
    q.push_back(v0);

    while (q.size()) {
        int u = q.front();
        q.pop_front();
        m[u] = 0;
        for (int v : g[u]){
            if (d[v0][v] > d[v0][u] + d[u][v]) {
                d[v0][v] = d[v0][u] + d[u][v];
                if (m[v] == 2){
                    m[v] = 1;
                    q.push_back(v);
                }
                else if (m[v] == 0){
                    m[v] = 1;
                    q.push_front(v);
                }
            }
        }
        if (u == v0 && !d[v0][v0]) d[v0][v0] = INF;
    }
    if (d[v0][v0] == INF) return -1;
    return d[v0][v0];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> T;
    while (T--){
        cin >> n >> m;
        fi(i, 1, n) g[i].clear();
        fi(i, 1, n) fi(j, 1, n) d[i][j] = INF;
        fi(i, 1, m){
            int u, v, w;
            cin >> u >> v >> w;
            if (d[u][v] == INF) g[u].emplace_back(v);
            if (d[u][v] > w) d[u][v] = w;
        }
        fi(i, 1, n) cout << shortest_paths(i) << '\n';
    }
}
