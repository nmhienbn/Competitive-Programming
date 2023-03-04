#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pli pair<ll,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define file freopen(Ahri".inp", "r", stdin); freopen(Ahri".out", "w", stdout);
#define Ahri "g"
const int maxn = 2e3+5;
const int maxm = 2e5+5;
const int maxp = 5e5+5;

using namespace std;

struct dl {
    int u, v, w;
} E[maxm];

int n, s, t, m;
ll d[maxn], L[maxn];
vector<pii> g[maxn];


void Dijkstra(vector<pii> edge[]){
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    fi(i, 1, n) d[i] = 1e18;
    d[t] = 0;
    pq.push({0, t});
    while (!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        for (auto vt : edge[u]){
            int v = vt.first, w = vt.second;
            if (d[v] > d[u] + w){
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }
}

void nhap(int x1, int x2){
    vector<pii> edge[maxn] = {};
    cin >> m;
    fi(i, 1, m){
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].pb({v, w});
        edge[v].pb({u, w});
        E[i] = {u, v, w};
    }
    Dijkstra(edge);
    fi(i, 1, m){
        int u = E[i].u, v = E[i].v, w = E[i].w;
        if (d[u] > d[v]) g[u+x1].pb({v+x2, w});
        if (d[u] < d[v]) g[v+x1].pb({u+x2, w});
    }
}

int onStack[maxn], cnt;
void DFS(int u){
    cnt++;
    if (onStack[u] || cnt >= maxp){
        cout << -1;
        exit(0);
    }
    onStack[u] = 1;
    for (auto vt : g[u]){
        int v = vt.first, w = vt.second;
        if (L[v] < L[u]+w){
            L[v] = L[u] + w;
            DFS(v);
        }
    }
    onStack[u] = 0;
}

int main(){
    faster
    cin >> n >> s >> t;
    nhap(n, 0);
    nhap(0, n);
    DFS(s+n);
    cout << max(L[t], L[t+n]);
}
