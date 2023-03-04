#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "fortune"
const int maxn = 1e5+5;

using namespace std;

int n, k, a[maxn], L[maxn];
vector<int> g[maxn];

void dfs(int u){
    L[u] = 0;
    for(auto v : g[u]){
        dfs(v);
        L[u] += L[v];
    }
    L[u] = max(L[u], a[u]);
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    int t;
    cin >> t;
    while (t--){
        cin >> n >> k;
        fi(i, 0, n){
            g[i].clear();
        }
        fi(i, 1, n){
            int u, w;
            cin >> u >> w;
            g[u].pb(i);
            a[i] = w;
        }
        dfs(0);
        cout << L[0] << ' ';
    }
}
