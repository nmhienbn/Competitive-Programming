#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pli pair<ll,int>
#define minimize(x,y) x = x > y ? y : x
#define pb push_back
#define ll long long
#define Irelia "delete"
const int maxn = 2e5 + 5;
const ll INF = 1e18;
const int mod = 998244353;
using namespace std;
using namespace __gnu_pbds;
tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ss;

int n, m, k, res = 1;
int mu[maxn];
vector<pii> g[maxn];
ll f[maxn], d[maxn];
int cnt[maxn];
bool xd[maxn];
priority_queue<pli, vector<pli>, greater<pli>> q;

void Dijkstra(){
    q.push({0, 1});
    fi(v, 2, n){
        if (d[v]){
            f[v] = d[v];
            q.push({f[v], v});
        }
    }
    while (q.size()){
        int u = q.top().second;
        if (q.top().first > f[u]){
            q.pop();
            continue;
        }
        q.pop();
        for (pii vt : g[u]){
            int v = vt.first, w = vt.second;
            if (f[u] + w <= d[v]) xd[v] = 1;
            if (f[v] > f[u] + w){
                f[v] = f[u] + w;
                q.push({f[v], v});
            }
        }
    }
    fi(i, 2, n){
        if (xd[i]) res = 1ll * res * mu[cnt[i]] % mod;
        else if (cnt[i]) res = (1ll * res * (mu[cnt[i]] - 1)) % mod;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m >> k;
    fi(i, 2, n) f[i] = INF;
    mu[0] = 1;
    fi(i, 1, k){
        mu[i] = mu[i - 1] << 1;
        if (mu[i] >= mod) mu[i] -= mod;
    }
    for (int i = 1, u, v, w; i <= m; i++){
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    for (int i = 1, v, w; i <= k; i++){
        cin >> v >> w;
        if (d[v]){
            if (d[v] == w){
                cnt[v]++;
            }
            else if (d[v] > w){
                res = 1ll * res * mu[cnt[v]] % mod;
                d[v] = w;
                cnt[v] = 1;
            }
            else {
                res <<= 1;
                if (res >= mod) res -= mod;
            }
        }
        else {
            d[v] = w;
            cnt[v] = 1;
        }
    }
    Dijkstra();
    cout << res;
}
