#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "atcoder_dp_p"
const int maxn = 1e5+5, mod = 1e9+7;

using namespace std;

int n;
ll dp[maxn][2];
vector<int> g[maxn];

bool cl[maxn];
void dfs(int u){
    cl[u] = 1;
    dp[u][0] = dp[u][1] = 1;
    for (auto v : g[u]){
        if (cl[v]) continue;
        dfs(v);
        dp[u][0] *= dp[v][0] + dp[v][1];
        dp[u][1] *= dp[v][0];
        dp[u][0] %= mod;
        dp[u][1] %= mod;
    }
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    fi(i, 2, n){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1);
    cout << (dp[1][0] + dp[1][1]) % mod;
}
