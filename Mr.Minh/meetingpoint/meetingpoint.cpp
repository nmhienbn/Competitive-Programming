#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pll pair <ll, ll>
#define pb push_back
#define Irelia "meetingpoint"
const int maxn = 1e5+5;
using namespace std;

int n, m, k;
pll L[maxn];
vector<pii> g[maxn];

bool cmp(pll a, pll b){
    return a.first*b.second < a.second*b.first;
}

void Dijkstra(int st){
    fi(i, 1, n) L[i].first = 1e18;
    L[st].first = 0;
    priority_queue<pll, vector<pll>, greater<pll>> q;
    q.push({0, st});
    while (q.size()){
        int u = q.top().second;
        q.pop();
        for (auto vt : g[u]){
            int v = vt.first, w = vt.second;
            if (L[v].first > L[u].first + w){
                L[v].first = L[u].first + w;
                q.push({L[v].first, v});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m >> k;
    fi(i, 1, m){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    Dijkstra(n);
    fi(i, 1, n) swap(L[i].first, L[i].second);
    Dijkstra(1);
    if (n*k <= 2e7){
        fi(i, 1, k){
            int u, v;
            cin >> u >> v;
            ll res = 1e18;
            fi(i, 1, n){
                res = min(res, max(L[i].first*u, L[i].second*v));
            }
            cout << res << '\n';
        }
        exit(0);
    }
    sort(L+1, L+n+1, cmp);
    fi(i, 1, k){
        int u, v;
        cin >> u >> v;
        int d = 1, c = n;
        while (d <= c){
            int g = (d + c) >> 1;
            if (L[g].first*u >= L[g].second*v) c = g-1;
            else d = g+1;
        }
        cout << min({max(L[d].first*u, L[d].second*v),
                    max(L[max(d-1, 1)].first*u, L[max(d-1, 1)].second*v),
                    max(L[min(d+1, n)].first*u, L[min(d+1, n)].second*v)}) << '\n';
    }
}
