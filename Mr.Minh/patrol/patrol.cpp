#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "patrol"
const int maxn = 1e5+5;
using namespace std;

int n, L[maxn];
vector<int> g[maxn];

void dfs(int u){
    for (int v : g[u]){
        if (L[v]) continue;
        L[v] = L[u] + 1;
        dfs(v);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 2, n){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    L[1] = 1;
    dfs(1);
    int vt = max_element(L+1, L+n+1) - L;
    fi(i, 1, n) L[i] = 0;
    L[vt] = 1;
    dfs(vt);
    cout << n*2-*max_element(L+1, L+n+1);
}
