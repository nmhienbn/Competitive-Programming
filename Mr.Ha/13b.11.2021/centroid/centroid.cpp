#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL);
#define NunuAndWillump "centroid"
const int maxn = 1e5+5;

using namespace std;

int n, d1[maxn], d2[maxn], dis = 1e9;
vector<int> g[maxn];
vector<int> res;

void dfs(int u, int par, int d[]){
    for (int v : g[u]){
        if (v == par) continue;
        d[v] = d[u] + 1;
        dfs(v, u, d);
    }
}

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n;
    fi(i, 2, n){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1, 0, d1);
    int vt = max_element(d1+1, d1+n+1) - d1;
    d1[vt] = 0;
    dfs(vt, 0, d1);
    vt = max_element(d1+1, d1+n+1) - d1;
    dfs(vt, 0, d2);
    fi(i, 1, n){
        if (max(d1[i], d2[i]) < dis){
            res.clear();
            res.pb(i);
            dis = max(d1[i], d2[i]);
        }
        else if (max(d1[i], d2[i]) == dis){
            res.pb(i);
        }
    }
    sort(res.begin(), res.end());
    cout << res.size() << '\n';
    for (auto u : res) cout << u << ' ';
}
