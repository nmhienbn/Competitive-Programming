#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "stock"
const int maxn = 240;

using namespace std;

int n, t, par[maxn], cnt;
bool check[maxn][maxn];
vector<int> g[maxn];

bool cl[maxn];
void dfs(int u, int source){
    cl[u] = 1;
    for (auto v : g[u]){
        if (cl[v]) continue;
        check[source][v] = 1;
        dfs(v, source);
    }
}

int main(){
    faster
    freopen(Seraphine".in", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> t;
    while (t--){
        int u, v;
        cin >> u >> v;
        if (check[v][u]){
            cnt++;
            continue;
        }
        fi(i, 1, n) cl[i] = 0;
        g[u].pb(v);
        dfs(u, u);
    }
    cout << cnt;
}
