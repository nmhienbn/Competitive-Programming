#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define minimize(x, y) x = x > y ? y : x
#define pb push_back
#define ll long long
#define Irelia "edge"
const int maxn = 2e5 + 5;
using namespace std;

struct edge {
    int u, v;
    bool ok;
    int other (int x){
        return u ^ v ^ x;
    }
};

int n, m;
int low[maxn], num[maxn], cntNode;
int id, cnt[maxn], bridge[maxn], bridges;
ll lanes;
int child[maxn];
edge a[maxn];
vector<int> g[maxn];

void dfs(int u){
    low[u] = num[u] = ++cntNode;
    cnt[id]++;
    child[u] = 1;
    for (int i : g[u]) if (!a[i].ok){
        a[i].ok = 1;
        int v = a[i].other(u);
        if (num[v])
            minimize(low[u], num[v]);
        else {
            dfs(v);
            child[u] += child[v];
            minimize(low[u], low[v]);
            if (low[v] > num[u]){
                bridge[id]++;
                lanes += 1ll * child[v] * (n - child[v]) - 1;
            }
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
        a[i] = {u, v, 0};
        g[u].pb(i);
        g[v].pb(i);
    }
    fi(i, 1, n) if (!num[i]){
        id++;
        dfs(i);
        bridges += bridge[id];
    }
    if (id > 2){
        cout << 0;
        exit(0);
    }
    if (id == 2){
        cout << 1ll * cnt[1] * cnt[2] * (m - bridges);
        exit(0);
    }
    //id = 1
    cout << (1ll * n * (n - 1) / 2 - m) * (m - bridges) + lanes;
}
