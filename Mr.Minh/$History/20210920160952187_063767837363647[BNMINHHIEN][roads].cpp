#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "roads"
const int maxn = 105, maxk = 10005;

using namespace std;

struct dl {
    int u, v;
     w;
    bool operator < (const dl& x) const {
        return w > x.w;
    }
};

int n, m, k;
ll L[maxn][maxk], res = 1e18;
vector<dl> g[maxn];
priority_queue<dl> q;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> m >> k;
    fi(i, 1, m){
        int u, v, w, t;
        cin >> u >> v >> w >> t; // u, v, len, le phi
        g[u].pb({v, w, t});
    }
    fi(i, 1, n) fi(j, 0, k) L[i][j] = 1e18;
    L[1][0] = 0;
    q.push({1, 0, 0}); // u, le phi, L[u][le phi]
    while (q.size()){
        int u = q.top().u, x = q.top().v;
        q.pop();
        for (auto vt : g[u]){
            int v = vt.u, w = vt.v, t = vt.w;
            if (x+t > k) continue;
            if (L[v][x+t] > L[u][x] + w){
                L[v][x+t] = L[u][x] + w;
                q.push({v, x+t, L[v][x+t]});
            }
        }
    }
    fi(i, 0, k) res = min(res, L[n][i]);
    cout << (res == 1e18 ? -1 : res);
}
