#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <ll, int>
#define pb push_back
#define Irelia "minpath"
const int maxn = 1e5+5;
using namespace std;

int n, m, s, t, b[maxn][18], h[maxn], res[maxn], id;
ll L[maxn];
vector<pii> g[maxn];
priority_queue<pii, vector<pii>, greater<pii>> q;

int calc(int u, int v){
    if (h[u] < h[v]) swap(u, v);
    int uu = u, vv = v;
    int d = h[u] - h[v], kt = log2(h[u]);
    fid(i, kt, 0) if ((d >> i) & 1) u = b[u][i];
    if (u == v) return vv;
    fid(i, kt, 0){
        if (b[u][i] != b[v][i]){
            u = b[u][i];
            v = b[v][i];
        }
    }
    if (u < v) return uu;
    return vv;
}

void Dijkstra(){
    fi(i, 1, n) L[i] = 1e18;
    L[s] = 0;
    q.push({0, s});
    while (q.size()){
        int u = q.top().second;
        ll c = q.top().first;
        q.pop();
        if (u == t) break;
        if (c > L[u]) continue;
        for (auto vt : g[u]){
            int v = vt.first, w = vt.second;
            if (L[v] > L[u] + w){
                L[v] = L[u] + w;
                q.push({L[v], v});
                h[v] = h[u] + 1;
                b[v][0] = u;
                int kt = log2(h[v]);
                fi(i, 1, kt) b[v][i] = b[b[v][i-1]][i-1];
            }
            else if (L[v] == L[u] + w){
                int tmp = calc(u, v);
                if (b[v][0] != tmp){
                    b[v][0] = tmp;
                    h[v] = h[tmp] + 1;
                    int kt = log2(h[v]);
                    fi(i, 1, kt) b[v][i] = b[b[v][i-1]][i-1];
                }
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
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
    }
    cin >> s >> t;
    Dijkstra();
    cout << L[t] << '\n';
    res[++id] = t;
    while (t != s){
        t = b[t][0];
        res[++id] = t;
    }
    fid(i, id, 1) cout << res[i] << ' ';
}
