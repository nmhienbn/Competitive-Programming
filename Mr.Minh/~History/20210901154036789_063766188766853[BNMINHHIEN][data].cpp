#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "data"
const int maxn = 1005;

using namespace std;

int n, m, L[maxn][maxn];
vector<int> g[maxn];

bool cl[maxn];
void dfs(int u, int bg){
    cl[u] = 1;
    for (auto v : g[u]){
        if (cl[v]) continue;
        L[bg][v] = 1;
        dfs(v, bg);
    }
    cl[u] = 0;
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    while (cin >> n){
        if (n == 0) break;
        fi(i, 1, n){
            g[i].clear();
            fi(j, 1, n){
                L[i][j] = 0;
            }
        }
        cin >> m;
        fi(i, 1, m){
            int u, v;
            cin >> u >> v;
            g[u].pb(v);
        }
        fi(i, 1, n){
            dfs(i, i);
        }
        int res = 0;
        fi(u, 1, n){
            for (auto v : g[u]){
                if (L[v][u]) res++;
            }
        }
        cout << res << '\n';
    }
}
