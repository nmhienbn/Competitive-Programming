#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "kpaths"
const int maxn = 1e5 + 5;
using namespace std;

int n, k;
vector<int> g[maxn];

bool ok(vector<int> &d, int id){
    int u = 0, v = d.size() - 1;
    while (u < v){
        if (u == id) u++;
        if (v == id) v--;
        if (u < v && d[u] + d[v] < k) return 0;
        u++, v--;
    }
    return 1;
}

int dfs(int u, int p){
    vector<int> d;
    for (int v : g[u]) if (v != p){
        int l = dfs(v, u);
        if (l < 0) return -1;
        d.pb(l + 1);
    }
    if (d.size() % 2 == 0) d.pb(0);
    sort(d.begin(), d.end());
    if (!ok(d, 0)) return -1;
    int l = 0, r = d.size() - 1;
    while (l <= r){
        int mid = (l + r) >> 1;
        if (ok(d, mid)) l = mid + 1;
        else r = mid - 1;
    }
    if (u == 1 && d[r] < k) return d[0];
    return d[r];
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
    int d = 1, c = n - 1;
    while (d <= c){
        k = (d + c) >> 1;
        int l = dfs(1, 0);
        if (l >= k || l == 0) d = k + 1;
        else c = k - 1;
    }
    cout << c;
}
