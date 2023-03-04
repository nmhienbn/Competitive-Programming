#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "nonneg"
const int maxn = 25e3+5;

using namespace std;

int n, m, w, s, d[maxn];
vector<pii> g[maxn];

void init(){
    cin >> n >> m >> w >> s;
    fi(i, 1, m){
        int u, v, t;
        cin >> u >> v >> t;
        g[u].pb({v, t});
        g[v].pb({u, t});
    }
    fi(i, 1, w){
        int u, v, t;
        cin >> u >> v >> t;
        g[u].pb({v, t});
    }
    fi(i, 1, n) d[i] = 1e9;
    d[s] = 0;
}

priority_queue<pii, vector<pii>, greater<pii>> q;

bool cmp (pii a, pii b){
    return a.second < b.second;
}

void Dijkstra(){
    //clock_t st, en;
    //double res = 0;
    //ll cnt = 0;
    //int dem = 0;
    q.push({0, s});
    while (q.size()){
        //dem = max(dem, int(q.size()));
        //st = clock();
        int u = q.top().second, C = q.top().first;
        q.pop();
        //en = clock();
        //res = max(res, double(en-st)/CLOCKS_PER_SEC);
        if (C > d[u]) continue;
        //if (cnt > 1e7) break;
        for (auto vt : g[u]){
            //cnt++;
            int v = vt.first, t = vt.second;
            if (d[v] > d[u] + t){
                d[v] = d[u] + t;
                q.push({d[v], v});
            }
        }
    }
    //cout << res << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    init();
    fi(i, 1, n) sort(g[i].begin(), g[i].end(), cmp);
    Dijkstra();
    fi(i, 1, n){
        if (d[i] == 1e9) cout << "NO PATH\n";
        else cout << d[i] << '\n';
    }
}
