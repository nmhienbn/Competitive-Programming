#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "chemistry"
const int maxn = 55;
using namespace std;

int n, m, res, cnt;
bool cl[maxn];
vector<int> g[maxn];

void dfs(int u){
    cl[u] = 1;
    for (int v : g[u]) if (!cl[v]){
        dfs(v);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, m){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    res = n;
    fi(i, 1, n) if (!cl[i]){
        dfs(i);
        res--;
    }
    cout << (1ll << res);
}
