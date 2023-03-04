#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "buatiec"
const int maxn = 2005;
using namespace std;

int n, h[maxn], f[maxn][2], res = -1e9;
vector<int> g[maxn];

void dfs(int u, int p){
    f[u][1] = h[u];
    for (int v : g[u]){
        if (v == p) continue;
        dfs(v, u);
        f[u][1] += max(f[v][0], 0);
        f[u][0] += max({0, f[v][1], f[v][0]});
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> h[i];
    fi(i, 1, n - 1){
        int u, v;
        cin >> u >> v;
        g[v].pb(u);
    }
    fi(i, 1, n){
        fi(j, 1, n) fi(k, 0, 1) f[j][k] = 0;
        dfs(i, 0);
        res = max(res, f[i][1]);
    }
    cout << res;
}
