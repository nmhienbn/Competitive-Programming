#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "grcolor"
const int maxn = 1e5 + 5;
using namespace std;

int n, m, q;
int res[maxn];
vector<int> g[maxn];
int cl[maxn];

struct dl {
    int u, d, c;
} a[maxn];

void dfs(int u, int p, int d, int c){
    if (cl[u] >= d) return;
    if (cl[u] < d) cl[u] = d;
    if (!res[u]) res[u] = c;
    for (int v : g[u]) if (v != p){
        if (d) dfs(v, u, d - 1, c);
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
    fi(i, 1, n) cl[i] = -1;
    cin >> q;
    fi(i, 1, q){
        cin >> a[i].u >> a[i].d >> a[i].c;
    }
    fid(i, q, 1){
        dfs(a[i].u, 0, a[i].d, a[i].c);
    }
    fi(i, 1, n) cout << res[i] << '\n';
}
