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
#define Seraphine "graph"

using namespace std;

int n, m, par[maxn], num[maxn], low[maxn], id;
vector<int> g[maxn];
int bridge, hinge;
bool kt[maxn];

void dfs(int u){
    int child = (par[u] != -1);
    num[u] = low[u] = ++id;
    for (auto v : g[u]){
        if (par[u] == v) continue;
        if (num[v]){
            low[u] = min(low[u], num[v]);
        }
        else {
            par[v] = u;
            dfs(v);
            low[u] = min(low[u], low[v]);
            if (low[v] >= num[u]){
                child++;
            }
        }
        if (low[v] > num[u]) bridge++;
    }
    if (child > 1) hinge++;
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
    fi(i, 1, n ){
        if (!par[i]){
            par[i] = -1;
            dfs(i);
        }
    }
    cout << hinge << ' ' << bridge;
}
