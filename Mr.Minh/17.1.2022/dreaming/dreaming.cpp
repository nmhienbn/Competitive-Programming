#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "dreaming"
const int maxn = 1e5 + 5;
using namespace std;

int n, m, l;
vector<pii> g[maxn];
int st[maxn], top;
int d[maxn][2], f[maxn];
bool cl[maxn];
int h[maxn], tp, res;

void dfs(int u){
    cl[u] = 1;
    st[++top] = u;
    for (pii vt : g[u]){
        int v = vt.first, w = vt.second;
        if (cl[v]) continue;
        dfs(v);
        if (d[v][0] + w > d[u][0]){
            d[u][1] = d[u][0];
            d[u][0] = d[v][0] + w;
        }
        else if (d[v][0] + w > d[u][1]){
            d[u][1] = d[v][0] + w;
        }
    }
}

void dfs(int u, int p){
    for (pii vt : g[u]){
        int v = vt.first, w = vt.second;
        if (v == p) continue;
        if (d[u][0] == d[v][0] + w){
            f[v] = d[u][1] + w;
        }
        else {
            f[v] = d[u][0] + w;
        }
        f[v] = max(f[v], f[u] + w);
        dfs(v, u);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m >> l;
    if (n == 1){
        cout << 0;
        exit(0);
    }
    fi(i, 1, m){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    fi(i, 0, n - 1) if (!cl[i]){
        top = 0;
        dfs(i);
        dfs(i, -1);
        h[++tp] = 1e9;
        fi(j, 1, top){
            h[tp] = min(h[tp], max(d[st[j]][0], f[st[j]]));
            res = max(res, d[st[j]][0] + f[st[j]]);
        }
    }
    sort(h + 1, h + tp + 1, greater<int>());
    if (tp == 2) cout << max(h[1] + h[2] + l, res);
    else cout << max({h[1] + h[2] + l, h[2] + h[3] + l * 2, res});
}
