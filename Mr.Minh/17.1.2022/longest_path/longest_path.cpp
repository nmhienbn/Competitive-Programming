#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "longest_path"
const int maxn = 1e6 + 5;
using namespace std;

int n;
ll d[maxn], d1[maxn];
vector<pii> g[maxn];

void dfs(int u, int p, ll d[]){
    for (pii vt : g[u]){
        int v = vt.first, w = vt.second;
        if (v == p) continue;
        d[v] = d[u] + w;
        dfs(v, u, d);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n - 1){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    dfs(1, 0, d);
    int vt = max_element(d + 1, d + n + 1) - d;
    dfs(vt, 0, d1);
    cout << *max_element(d1 + 1, d1 + n + 1);
}
