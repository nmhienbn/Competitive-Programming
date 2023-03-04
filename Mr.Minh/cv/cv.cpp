#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "cv"
const int maxn = 15e4+5;
using namespace std;

int n, m, res, k;
vector<int> g[maxn];

bool cl[maxn];
void dfs(int u){
    cl[u] = 1;
    for (int v : g[u]){
        if (!cl[v]){
            dfs(v);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, m){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    fi(i, 1, n) if (!cl[i]){
        k++;
        dfs(i);
    }
    cout << m-n+k;
}
