#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "bestspot"
const int maxn = 505;

using namespace std;

int n, p, m, yt[maxn], id;
ll L[maxn], res = 1e18;
vector<pii> g[maxn];

void Dijkstra(int st){
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, st});
    fi(i, 1, n) L[i] = 1e18;
    L[st] = 0;
    while (q.size()){
        int u = q.top().second;
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

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> p >> m;
    fi(i, 1, p) cin >> yt[i];
    fi(i, 1, m){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    fi(i, 1, n){
        Dijkstra(i);
        ll ans = 0;
        fi(i, 1, p) ans += L[yt[i]];
        if (res > ans){
            res = ans;
            id = i;
        }
    }
    cout << id;
}
