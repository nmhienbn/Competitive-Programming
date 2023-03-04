#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "g2w"
const int maxn = 1e4 + 5, INF = 1e9;
using namespace std;

int n, m, a, b, f[maxn];
vector<pii> g[maxn];
bool c1[maxn], c2[maxn];
priority_queue<pii, vector<pii>, greater<pii>> q;

void Dijkstra(int st, int fn, bool cl[]){
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
        if (u == fn) return;
        q.pop();
        for (pii vt : g[u]){
            int v = vt.first, w = vt.second;
            if (!cl[v] && f[v] > f[u] + w){
                f[v] = f[u] + w;
                q.push({f[v], v});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m >> a >> b;
    fi(i, 1, a){
        int x; cin >> x;
        c1[x] = 1;
    }
    fi(i, 1, b){
        int x; cin >> x;
        c2[x] = 1;
    }
    fi(i, 1, m){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
    }
    Dijkstra(1, n, c1);
    cout << f[n] << ' ';
    Dijkstra(n, 1, c2);
    cout << f[1];
}
