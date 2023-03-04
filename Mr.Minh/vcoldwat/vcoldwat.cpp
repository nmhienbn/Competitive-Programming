#include <bits/stdc++.h>
#define fi(i,a,b) for(int i=a; i<=b; i++)
#define fid(i,a,b) for(int i=a; i>=b; i--)
#define fir first
#define se second
#define bit(i,j) ((i>>j)&1)
#define bit2(i) (1<<(i-1))
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

#define maxn 100005
#define maxm 1000006
#define MOD
#define Seraphine "vcoldwat"

using namespace std;

int n, m, h[maxn];
vector<int> g[maxn];

void dfs(int u){
    for (auto v : g[u]){
        if (h[v]) continue;
        h[v] = h[u] + 1;
        dfs(v);
    }
}

int main(){
    faster
    freopen(Seraphine".inp","r",stdin);
    freopen(Seraphine".out","w",stdout);
    cin >> n >> m;
    fi(i, 1, m){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb(v);
        g[u].pb(w);
    }
    h[1] = 1;
    dfs(1);
    fi(i, 1, n){
        cout << h[i] << '\n';
    }
}
