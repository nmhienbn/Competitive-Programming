#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "destroy"
const int maxn = 2e5+5;

using namespace std;

int n, k, res;
vector<int> g[maxn];
int d[maxn][2];

void dfs(int u, int p){
    for (auto v : g[u]){
        if (v == p) continue;
        dfs(v, u);
        if (d[v][0] + 1 > d[u][0]){
            d[u][1] = d[u][0];
            d[u][0] = d[v][0] + 1;
        }
        else if (d[v][0] + 1 > d[u][1]){
            d[u][1] = d[v][0] + 1;
        }
    }
    if (d[u][0] + d[u][1] >= k){
        res++;
        d[u][0] = d[u][1] = -1;
    }
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> k;
    fi(i, 2, n){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1, 0);
    cout << res;
}
