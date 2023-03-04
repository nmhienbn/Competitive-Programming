#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "robbery"
const int maxn = 105, INF = 1e9;

using namespace std;

int n, m, e, plane[maxn], pol[maxn], st1, st2, rob[maxn];
vector<pii> g[maxn];

void Dijkstra(int st, int L[]){
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, st});
    fi(i, 1, n) L[i] = INF;
    L[st] = 0;
    while (q.size()){
        int u = q.top().second;
        if (q.top().first > L[u]){
            q.pop();
            continue;
        }
        q.pop();
        for (pii vt : g[u]){
            int v = vt.first, w = vt.second;
            if (L[v] > L[u] + w){
                L[v] = L[u] + w;
                q.push({L[v], v});
            }
        }
    }
}

bool check(int st, int L[], double val){
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, st});
    fi(i, 1, n) L[i] = INF;
    L[st] = 0;
    while (q.size()){
        int u = q.top().second;
        if (q.top().first > L[u]){
            q.pop();
            continue;
        }
        q.pop();
        for (pii vt : g[u]){
            int v = vt.first, w = vt.second;
            int l = L[u] + w;
            if (L[v] > l && 160.0 * l < pol[v] * val){
                L[v] = L[u] + w;
                q.push({L[v], v});
            }
        }
    }
    fi(i, 1, e){
        if (L[plane[i]] < INF) return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m >> e;
    fi(i, 1, m){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    fi(i, 1, e) cin >> plane[i];
    cin >> st1 >> st2;
    Dijkstra(st2, pol);
    double d = 0, c = 1e9;
    fi(rep, 1, 70){
        double g = (d + c) / 2;
        if (check(st1, rob, g)) c = g;
        else d = g;
    }
    if (check(st1, rob, d + 0.0000001)) cout << fixed << setprecision(6) << d;
    else cout << "IMPOSSIBLE";
}
