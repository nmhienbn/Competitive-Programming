#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "KIOSKS"
const int maxn = 1e4+5;
const int mod = 1e9+7;

using namespace std;

int n, k, c[maxn];
ll L[maxn][1 << 10], cnt[maxn][1 << 10], ttc, res, con[maxn];
vector<int> g[maxn];

int cl[maxn];
void dfs(int u){
    cl[u] = 1;
    for (auto v : g[u]){
        if (cl[v]) continue;
        int t = 0;
        if (c[u] <= k) t = (1 << (c[u]-1));
        dfs(v);
        fi(i, 0, ttc){
            L[u][i|t] += L[v][i];
            L[u][i|t] %= mod;
        }
    }
    if (c[u] <= k) L[u][1 << (c[u]-1)] = (L[u][1 << (c[u]-1)]+1)%mod;
    else L[u][0] += (L[u][0]+1)%mod;
}

void dfs1(int u){
    cl[u] = 1;
    if (c[u] == 1) L[u][1] = 1;
    else L[u][0] = 1;
    for (auto v : g[u]){
        if (cl[v]) continue;
        dfs1(v);
        if (c[u] != 1 && L[v][1] != 0) con[u]++;
        if (c[u] == 1){
            if (!L[u][1]) L[u][1] = 1;
            L[u][1] *= (L[v][0]+L[v][1]+1);
            L[u][1] %= mod;
        }
        else {
            if (!L[u][0]) L[u][0] = 1;
            L[u][0] *= (L[v][0]+1);
            L[u][0] %= mod;
            if (!L[u][1]) L[u][1] = 1;
            L[u][1] *= (L[v][1]+1);
            L[u][1] %= mod;
        }
    }
    if (con[u] == 1) L[u][1] = (L[u][1]+mod-1)%mod;
}

int main(){
    faster
    cin >> n >> k;
    ttc = (1 << k) - 1;
    fi(i, 1, n) cin >> c[i];
    fi(i, 1, n-1){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    if (k == 1) dfs1(1);
    else dfs(1);
    fi(i, 1, n){
        res += L[i][ttc];
    }
    cout << res;
}
