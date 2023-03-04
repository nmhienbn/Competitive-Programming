#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "vocv"
const int maxn = 100020, mod = 10007;

using namespace std;

int n, a[maxn], t, d[maxn][2], way[maxn][2], vt, tt;
vector<int> g[maxn];

bool cl[maxn];
void dfs(int u){
    way[u][0] = way[u][1] = d[u][1] = 1;
    cl[u] = 1;
    for (auto v : g[u]){
        if (cl[v]) continue;
        dfs(v);
        d[u][1] += min(d[v][0], d[v][1]);
        d[u][0] += d[v][1];

        way[u][0] = (way[u][0] * way[v][1]) % mod;
        if (d[v][0] < d[v][1]) way[u][1] = (way[u][1] * way[v][0]) % mod;
        else if (d[v][0] > d[v][1]) way[u][1] = (way[u][1] * way[v][1]) % mod;
        else way[u][1] = (way[u][1] * (way[v][1] + way[v][0])) % mod;
    }
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> t;
    while (t--){
        cin >> n;
        fi(i, 1, n){
            g[i].clear();
            cl[i] = 0;
            fi(j, 0, 1){
                d[i][j] = way[i][j] = 0;
            }
        }
        fi(i, 1, n-1){
            int u, v;
            cin >> u >> v;
            g[u].pb(v);
            g[v].pb(u);
        }
        dfs(1);
        cout << min(d[1][1], d[1][0]) << ' ';
        if (d[1][0] < d[1][1]) cout << way[1][0];
        else if (d[1][0] > d[1][1]) cout << way[1][1];
        else cout << (way[1][1] + way[1][0]) % mod;
        cout << '\n';
    }
}
