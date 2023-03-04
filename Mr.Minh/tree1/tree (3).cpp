#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL);
#define NunuAndWillump "tree"
const int maxn = 1e5+5;

using namespace std;

int n, m, l[maxn], a[maxn], typ[maxn];
vector<int> g[maxn];

void dfs(int u){
    if (typ[u] == 0){
        l[u] = 1;
    }
    if (typ[u] == 1){
        l[u] = 1e9;
        for (int v : g[u]){
            dfs(v);
            l[u] = min(l[u], l[v]);
        }
    }
    if (typ[u] == 2){
        for (int v : g[u]){
            dfs(v);
            l[u] += l[v];
        }
    }

}

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, m) cin >> a[i];
    sort(a+1, a+m+1, greater<int>());
    fi(i, 1, n){
        int u, v, t;
        cin >> t >> u >> v;
        typ[i] = t;
        if (u != 0) g[i].pb(u);
        if (v != 0) g[i].pb(v);
    }
    dfs(1);
    cout << a[l[1]];
}
