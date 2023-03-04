#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "airways"
const int maxn = 1005, maxc = 105;

using namespace std;

struct dl {
    int w, u, l;
    bool operator < (const dl& x) const {
        return w > x.w;
    }
};

int n, m, c, k, L[maxn][maxc], res = 1e9;
vector<pii> g[maxn];
bool kt[maxn];

void Dijkstra(){
    fi(i, 1, n) fi(j, 0, c) L[i][j] = 1e9;
    L[1][0] = 0;
    priority_queue<dl> q;
    q.push({0, 1, 0});
    while (q.size()){
        int u = q.top().u, l = q.top().l;
        q.pop();
        for (auto vt : g[u]){
            int v = vt.first, w = vt.second;
            if (l + w > c) continue;
            if (kt[v]){
                if (L[u][l] + w < L[v][0]){
                    L[v][0] = L[u][l] + w;
                    q.push({L[v][0], v, 0});
                }
            }
            else {
                if (L[u][l] + w < L[v][l+w]){
                    L[v][l+w] = L[u][l] + w;
                    q.push({L[v][l+w], v, l+w});
                }
            }
        }
    }
}

int main(){
    faster
    freopen(Seraphine".in", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> m >> c >> k;
    fi(i, 1, m){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    fi(i, 1, k){
        int u;
        cin >> u;
        kt[u] = 1;
    }
    Dijkstra();
    fi(i, 0, c) res = min(res, L[n][i]);
    cout << res;
}
