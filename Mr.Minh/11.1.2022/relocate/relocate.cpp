#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pli pair<ll, int>
#define pb push_back
#define ll long long
#define Irelia "relocate"
const int maxn = 1e4 + 5;
const ll INF = 1e18;
using namespace std;

int n, m, k, a[10], b[10];
ll f[10][maxn], L[10][10], res;
bool cl[maxn], c[10];
vector<pii> g[maxn];
priority_queue<pli, vector<pli>, greater<pli>> q;

void Dijkstra(int st, ll f[]){
    while (q.size()) q.pop();
    fi(i, 1, n) f[i] = INF;
    f[st] = 0;
    q.push({0, st});
    while (q.size()){
        int u = q.top().second;
        if (f[u] < q.top().first){
            q.pop();
            continue;
        }
        q.pop();
        for (pii vt : g[u]){
            int v = vt.first, w = vt.second;
            if (f[v] > f[u] + w){
                f[v] = f[u] + w;
                q.push({f[v], v});
            }
        }
    }
}

void minimize(ll& x, ll y){
    if (x > y) x = y;
}

void xuli(){
    ll ans = 0;
    fi(i, 1, k - 1){
       ans += f[b[i]][a[b[i + 1]]];
    }
    minimize(L[b[1]][b[k]], ans);
}

void ql(int i){
    fi(j, 1, k) if (!c[j]){
        b[i] = j;
        c[j] = 1;
        if (i < k) ql(i + 1);
        else xuli();
        c[j] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m >> k;
    fi(i, 1, k){
        cin >> a[i];
        cl[a[i]] = 1;
    }
    fi(i, 1, m){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    fi(i, 1, k) Dijkstra(a[i], f[i]);
    fi(i, 1, k) fi(j, 1, k) L[i][j] = INF;
    ql(1);
    res = INF;
    fi(i, 1, n) if (!cl[i]){
        fi(j, 1, k) fi(t, 1, k) if (j != t){
            minimize(res, f[j][i] + f[t][i] + L[j][t]);
        }
    }
    cout << res;
}
