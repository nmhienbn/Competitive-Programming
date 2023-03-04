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

#define maxn 2005
#define maxm 1000006
#define MOD
#define Seraphine "ads"

using namespace std;

int n, m, res;
vector<int> g[maxn];

bool cl[maxn], cl2[maxn];
int dfs(int u, int par){
    cl[u] = 1;
    cl2[u] = 1;
    int res = 0;
    for (auto v : g[u]) if (v != par){
        if (cl[v]) res++;
        if (!cl2[v]) res += dfs(v, u);
    }
    cl[u] = 0;
    return res;
}

int main(){
    faster
    freopen(Seraphine".inp","r",stdin);
    freopen(Seraphine".out","w",stdout);
    cin >> n >> m;
    fi(i, 1, m){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    fi(i, 1, n) if (!cl2[i]) res += dfs(i, 0);
    cout << res;
}
