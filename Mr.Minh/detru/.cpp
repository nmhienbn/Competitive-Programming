#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define file freopen(Ahri".inp", "r", stdin); freopen(Ahri".out", "w", stdout);
#define Ahri "QHD"
const int maxn = 1e4+5;

using namespace std;

struct data {
    int u, w;
    bool operator < (const data& x) const {
        return w > x.w;
    }
};

int n, m, k, d1[maxn], dk[maxn], dkn[maxn], dn[maxn], res = 1e9;
vector<pii> bo[maxn], bon[maxn], xe[maxn], xen[maxn];

void Dijkstra(int bd, int d[], vector<pii> edge[maxn]){
    fi(i, 1, n) d[i] = 1e9;
    priority_queue<data> pq;
    pq.push({bd, 0});
    d[bd] = 0;
    while (!pq.empty()){
        int u = pq.top().u;
        //cout << u << ' ';
        pq.pop();
        for (auto vt : edge[u]){
            int v = vt.first, w = vt.second;
            if (d[v] > d[u] + w){
                d[v] = d[u] + w;
                pq.push({v, d[v]});
            }
        }
    }
    //fi(i, 1, n) cout << d[i] << ' '; cout << '\n';
}

int main(){
    faster
    cin >> n >> m >> k;
    fi(i, 1, m){
        int u, v, w1, w2;
        cin >> u >> v >> w1 >> w2;
        bo[u].pb({v, w1});
        bon[v].pb({u, w1});
        xe[u].pb({v, w2});
        xen[v].pb({u, w2});
    }
    Dijkstra(1, d1, xe);
    Dijkstra(k, dk, bon);
    Dijkstra(n, dn, xen);
    fi(u, 1, n){
        if (d1[u] + dk[u] < 60){
            //cout << d1[u] + dn[u] << '\n';
            res = min(res, d1[u] + dn[u]);
        }
    }
    cout << res;
}
