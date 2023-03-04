#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "tour"
const int maxn = 1005;

using namespace std;

int n, m, k, s[20];
ll L[20][maxn], res = 1e18;
bool kt[maxn];
vector<pii> g[maxn];

void Dijkstra(int bd, int i){
    priority_queue<pii, vector<pii>, less<pii>> q;
    L[i][bd] = 0;
    q.push({0, bd});
    while (q.size()){
        int u = q.top().second;
        q.pop();
        for (auto vt : g[u]){
            int v = vt.first, w = vt.second;
            if (L[i][v] > L[i][u] + w){
                L[i][v] = L[i][u] + w;
                q.push({L[i][v], v});
            }
        }
    }
}

int x[20];
bool vis[20];
void xuli(){
    ll ans = 0;
    fi(i, 2, k) ans += L[x[i-1]][s[x[i]]];
    ans += L[0][s[x[1]]] + L[x[k]][1];
    res = min(res, ans);
}

void ql(int i){
    fi(j, 1, k) if (!vis[j]){
        x[i] = j;
        vis[j] = 1;
        if (i == k) xuli();
        else ql(i+1);
        vis[j] = 0;
    }
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> m >> k;
    fi(i, 0, k) fi(j, 1, n) L[i][j] = 1e18;
    fi(i, 1, k){
        cin >> s[i];
        kt[s[i]] = 1;
    }
    fi(i, 1, m){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
    }
    Dijkstra(1, 0);
    fi(i, 1, k){
        Dijkstra(s[i], i);
    }
    ql(1);
    cout << res;
}
