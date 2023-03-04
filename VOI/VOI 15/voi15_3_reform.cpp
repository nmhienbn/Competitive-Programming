#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define minimize(x,y) x = x > y ? y : x;
#define ll long long
#define Irelia "reform"
const int maxn = 2e5 + 5;
using namespace std;

int n, m;
vector<int> g[maxn];
int low[maxn], num[maxn], id;
int bridges;
int cnt, scc[maxn];
ll res;

int dfs(int u, int p){
    scc[cnt]++;
    low[u] = num[u] = ++id;
    int child = 1;
    for (int v : g[u]) if (v != p){
        if (num[v]){
            minimize(low[u], num[v]);
        }
        else {
            int childj = dfs(v, u);
            child += childj;
            minimize(low[u], low[v]);
            if (low[v] > num[u]){
                bridges++;
                res += 1ll * childj * (n - childj) - 1;
            }
        }
    }
    return child;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    //freopen(Irelia".inp", "r", stdin);
    //freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, m){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    fi(i, 1, n) if (!num[i]){
        cnt++;
        if (cnt > 2){
            cout << 0;
            exit(0);
        }
        dfs(i, 0);
    }
    if (cnt == 2){
        cout << 1ll * (m - bridges) * scc[1] * scc[2];
        exit(0);
    }
    cout << res + 1ll * (m - bridges) * (1ll * n * (n - 1) / 2 - m);
}
