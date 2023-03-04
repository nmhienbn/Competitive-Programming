#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "news"
const int maxn = 2e5 + 5;
using namespace std;

int n, q, par[maxn];
vector<int> g[maxn];
int a[maxn], h[maxn], root, res;
bool ok2 = 1;

struct query {
    int t, x, k;
} E[maxn];

void dfs(int u){
    for (int v : g[u]){
        if (v == par[u]) continue;
        par[v] = u;
        h[v] = h[u] + 1;
        dfs(v);
    }
}
void dfs(int u, int p, int k){
    if (k) a[u] = 1;
    res += a[u];
    for (int v : g[u]){
        if (v == p) continue;
        if (h[v] <= root){
            dfs(v, u, k);
        }
    }
}
void sub1(){
    cin >> q;
    int t, x, k;
    while (q--){
        cin >> t >> x >> k;
        root = h[x] + k;
        if (t == 1){
            dfs(x, par[x], 1);
        }
        else {
            res = 0;
            dfs(x, par[x], 0);
            cout << res << '\n';
        }
    }
    exit(0);
}

void sub2(){
    fi(i, 1, n) res += a[i];
    fi(i, 1, q){
        if (E[i].t == 1) res = n;
        cout << res << '\n';
    }
    exit(0);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n - 1){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    fi(i, 1, n) cin >> a[i];
    dfs(1);
    if (n <= 10000) sub1();
    cin >> q;
    fi(i, 1, q){
        int t, x, k;
        cin >> t >> x >> k;
        E[i] = {t, x, k};
        if (k != n) ok2 = 0;
    }
    if (ok2) sub2();
    sub2();
}
