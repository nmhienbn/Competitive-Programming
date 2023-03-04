#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "pt07x"
const int maxn = 1e5+5;

using namespace std;

int n, d[maxn][2];
vector<int> g[maxn];

bool cl[maxn];
void dfs(int u){
    d[u][1] = 1;
    cl[u] = 1;
    for (auto v : g[u]){
        if (cl[v]) continue;
        dfs(v);
        d[u][1] += min(d[v][1], d[v][0]);
        d[u][0] += d[v][1];
    }
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    fi(i, 2, n){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1);
    cout << min(d[1][1], d[1][0]);
}
