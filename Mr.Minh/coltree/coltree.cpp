#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "coltree"
const int maxn = 1e5+5;
using namespace std;

int n, q, a[maxn], bit[maxn], pre[maxn], b[maxn],
    in[maxn], out[maxn], id, nex[maxn], res[maxn], st;
vector<int> g[maxn], gt;
vector<pii> t[maxn];

void dfs(int u){
    in[u] = ++id;
    for (auto v : g[u]){
        if (!in[v]) dfs(v);
    }
    out[u] = id;
}

void update(int x, int val){
    if (x == 0) return;
    while (x <= n){
        bit[x] += val;
        x += x & -x;
    }
}

int get(int x){
    int ans = 0;
    while (x > 0){
        ans += bit[x];
        x -= x & -x;
    }
    return ans;
}

void enter(){
    cin >> n >> q >> st;
    fi(i, 2, n){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(st);
    fi(i, 1, n){
        cin >> a[in[i]];
        gt.pb(a[in[i]]);
        t[in[i]].pb({out[i], i});
    }
}

void process(){
    sort(gt.begin(), gt.end());
    gt.resize(unique(gt.begin(), gt.end()) - gt.begin());
    fi(i, 1, n){
        a[i] = lower_bound(gt.begin(), gt.end(), a[i]) - gt.begin() + 1;
    }
    fid(i, n, 1){
        b[i] = 1;
        nex[i] = pre[a[i]];
        b[pre[a[i]]] = 0;
        pre[a[i]] = i;
    }
    fi(i, 1, n) if (b[i]){
        update(i, 1);
    }
    fi(l, 1, n){
        update(l-1, -1);
        update(nex[l-1], 1);
        for (auto vt : t[l]){
            int r = vt.first, id = vt.second;
            res[id] = get(r) - get(l-1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    enter();
    process();
    while (q--){
        int id;
        cin >> id;
        cout << res[id] << '\n';
    }
}
