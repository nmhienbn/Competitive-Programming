#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "minpath"
const int maxn = 1e4+5;

using namespace std;

int n, u, v, w1, w2, d[maxn], d1[maxn], d2[maxn], id;
vector<pii> g[maxn];

bool cl[maxn];
void dfs(int u, int d[]){
    cl[u] = 1;
    for (auto vt : g[u]){
        int v = vt.first, w = vt.second;
        if (cl[v]) continue;
        d[v] = d[u] + w;
        dfs(v, d);
    }
    if (d[u] < d[id]) id = u;
}


int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    while (cin >> u >> v >> w1 >> w2){
        g[u].pb({v, w1-w2});
        g[v].pb({u, w1-w2});
    }
    d[0] = 1e9;
    dfs(1, d);
    int i1 = id; id = 0; d1[id] = 1e9;
    memset(cl, 0, sizeof(cl));
    dfs(i1, d1);
    cout << d1[id];
}
