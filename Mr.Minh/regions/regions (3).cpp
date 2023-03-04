#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL);
#define NunuAndWillump "regions"
const int maxn = 1e5+5;

using namespace std;

int n, m, scc, num[maxn];
ll cnt, res1, res2, dem, k;
vector<int> g[maxn];

bool cl[maxn];
void dfs(int u, int par){
    num[scc]++;
    cl[u] = 1;
    for (int v : g[u]) if (v != par){
        dfs(v, u);
    }
}

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n >> m >> k;
    fi(i, 1, m){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    fi(i, 1, n) if (!cl[i]){
        scc++;
        dfs(i, 0);
    }
    fi(i, 1, scc){
        cnt += dem*num[i];
        dem += num[i];
    }
    ll tg = 1ll*n*(n-1)/2 - cnt - m;
    //cout << cnt << ' ';
    res1 = res2 = scc;
    if (min(k, cnt) >= scc-1) res1 = 1;
    else res1 -= min(k, cnt);
    if (k > tg) k -= tg;
    cout << res1 << ' ' << res2;
}
