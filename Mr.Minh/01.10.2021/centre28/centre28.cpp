#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "centre28"
const int maxn = 30005;

using namespace std;

int n, m, L1[maxn], Ln[maxn];
ll T1[maxn], Tn[maxn];
vector<pii> g[maxn];

void Dijkstra(int st, int L[], ll T[]){
    priority_queue<pii, vector<pii>, greater<pii>> q;
    fi(i, 1, n) L[i] = 1e9;
    T[st] = 1;
    L[st] = 0;
    q.push({0, st});
    while (q.size()){
        int u = q.top().second, l = q.top().first;
        q.pop();
        if (l != L[u]) continue;
        for (pii vt : g[u]){
            int v = vt.first, w = vt.second;
            if (L[v] > L[u] + w){
                L[v] = L[u] + w;
                T[v] = T[u];
                q.push({L[v], v});
            }
            else if (L[v] == L[u] + w){
                T[v] += T[u];
            }
        }
    }
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, m){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    Dijkstra(1, L1, T1);
    Dijkstra(n, Ln, Tn);
    vector<int> res;
    fi(i, 2, n-1){
        if (L1[i] + Ln[i] > L1[n] || T1[i]*Tn[i] < T1[n]){
            res.pb(i);
        }
    }
    cout << res.size() << '\n';
    for (auto v : res) cout << v << '\n';
}
