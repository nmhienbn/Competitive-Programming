#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "dispatching"
const int maxn = 3e3 + 5;
using namespace std;

int n, m, a[maxn], b[maxn];
vector<int> g[maxn];

struct dl {
    int u;
    bool operator < (const dl x) const {
        return a[u] < a[x.u];
    }
};
priority_queue<dl> f[maxn];

void dfs(int u){
    int sum = 0;
    for (int v : g[u]){
        dfs(v);
    }
    if (sum + a[u] <= m) f[u].push(u);
    else if (f[u].size()){
        int v = f[u].top()
        if ()
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, n){
        int p;
        cin >> p >> a[i] >> b[i];
        g[p].pb(i);
    }
    dfs(0);

}
