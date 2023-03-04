#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "ndir"
const int maxn = 1e5 + 5;
using namespace std;

int n, m, num[maxn], low[maxn], id;
bool cl[maxn];
vector<int> g[maxn];
pii E[maxn];

void minimize(int& x, int y){
    if (x > y) x = y;
}

void dfs(int u, int p){
    num[u] = low[u] = ++id;
    for (int i : g[u]) if (!cl[i]){
        cl[i] = 1;
        int v = (E[i].first ^ E[i].second ^ u);
        if (v == p) continue;
        if (num[v]) minimize(low[u], num[v]);
        else {
            dfs(v, u);
            minimize(low[u], low[v]);
            if (low[v] >= num[v]) m--;
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
        E[i] = {u, v};
        g[u].pb(i);
        g[v].pb(i);
    }
    fi(i, 1, n) if (!num[i]) dfs(i, 0);
    cout << m;
}
