#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "nadjtrip"
const int maxn = 1e5+5;

using namespace std;

int n, child[maxn], sum1[maxn], sum2[maxn];
ll res;
vector<int> g[maxn];

void dfs(int u, int p){
    child[u] = 1;
    int sum = 0, sum1 = 0;
    for (int v : g[u]){
        if (v == p) continue;
        dfs(v, u);
        res += sum2[v];
        res += 1ll * sum * (child[v] - 1);

        child[u] += child[v];

        sum += child[v] - 1;
        sum2[u] +=  1ll * sum1 * child[v] + sum2[v];
        sum1 += child[v];
    }
    cout << sum2[u] << ' ';
    if (child[u] < n) res += sum * (n - child[u] - 1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n-1){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1, 0);
    cout << res;
}
