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
vector<pii> g[maxn];

int shortest_paths(int v0) {
    vector<int> d(n + 1, INF);
    d[v0] = 0;
    vector<int> m(n + 1, 2);
    deque<int> q;
    q.push_back(v0);

    while (q.size()) {
        int u = q.front();
        q.pop_front();
        m[u] = 0;
        for (pii e : g[u]) {
            int v = e.first;
            int w = e.second;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
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
        if (u == v0 && !d[v0]) d[v0] = INF;
    }
    if (d[v0] == INF) return -1;
    return d[v0];
}

bool cmp(pii a, pii b){
    return a.second < b.second;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    //freopen(Irelia".inp", "r", stdin);
    //freopen(Irelia".out", "w", stdout);
    cin >> T;
    while (T--){
        cin >> n >> m;
        fi(i, 1, n) g[i].clear();
        fi(i, 1, m){
            int u, v, w;
            cin >> u >> v >> w;
            g[u].emplace_back(make_pair(v, w));
        }
        fi(i, 1, n) sort(g[i].begin(), g[i].end(), cmp);
        fi(i, 1, n) cout << shortest_paths(i) << '\n';
    }
}
