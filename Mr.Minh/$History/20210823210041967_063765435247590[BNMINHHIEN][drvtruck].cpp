#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "drvtruck"
const int maxn = 5e5+5;

using namespace std;

int n, k, L[maxn], F[maxn], x;
bool kt[maxn];
vector<pii> g[maxn];

bool cl[maxn];
void dfs(int u){
    cl[u] = 1;
    for (auto vt : g[u]){
        int v = vt.first, w = vt.second;
        if (cl[v]) continue;
        dfs(v);
        if (kt[v]) F[u] += w*2;
        else if (F[v] != 0) F[u] += F[v] + w*2;
    }
}

void dfs2(int u){
    cl[u] = 1;
    for (auto vt : g[u]){
        int v = vt.first, w = vt.second;
        if (cl[v]) continue;
        if (L[u] || F[u] - F[v] - w*2)
            L[v] = L[u] + F[u] - F[v] + w*2;
        if (kt[v]) L[v] -= w*2;
        dfs2(v);
    }
}

int d1[maxn], vt, d2[maxn], cnt, d3[maxn];

void dfs(int u, int d[]){
    for (auto vt : g[u]){
        int v = vt.first, w = vt.second;
        if (d[v]) continue;
        d[v] = d[u] + w;
        dfs(v, d);
    }
    if (d[u] > d[vt] && kt[u]) vt = u;
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> k;
    fi(i, 1, n-1){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    fi(i, 1, k){
        cin >> x;
        kt[x] = 1;
    }
    dfs(1);
    memset(cl, 0, sizeof(cl));
    dfs2(1);
    d1[x] = 1;
    dfs(x, d1);
    d2[vt] = 1;
    dfs(vt, d2);
    d3[vt] = 1;
    dfs(vt, d3);
    //fi(i, 1, n) cout << L[i] << ' ' << F[i] << '\n';
    fi(i, 1, n){
        cout << F[i] + L[i] - max(d2[i]-1, d3[i]-1) << '\n';
    }
}
