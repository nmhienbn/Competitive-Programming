#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "swine"
const int maxn = 10005;
using namespace std;

int n, k, a[maxn], f[maxn];
vector<pii> g[maxn];

void dfs(int u, int p){
    for (pii it : g[u]){
        int v = it.first;
        int w = it.second;
        if (v == p) continue;
        if (a[v]){
            f[u] += w;
        }
        else {
            dfs(v, u);
            f[u] += min(w, f[v]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> k;
    fi(i, 1, k){
        int x;
        cin >> x;
        a[x] = 1;
    }
    fi(i, 2, n){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    dfs(1, 0);
    cout << f[1];
}
