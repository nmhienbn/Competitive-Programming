#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define file freopen(Ahri".inp", "r", stdin); freopen(Ahri".out", "w", stdout);
#define Ahri "holes"
const int maxn = 505;

using namespace std;

int ntest, n, m, w, c[maxn][maxn], d[maxn];
bool flag, cl[maxn];
vector<int> g[maxn];

void ds(int u, int v, int t){
    if (!c[u][v]){
        g[u].pb(v);
        c[u][v] = t;
    }
    else {
        c[u][v] = min(c[u][v], t);
    }
}

void dfs(int u){
    if (flag) return;
    cl[u] = 1;
    for (auto v : g[u]){
        if (d[v] > d[u] + c[u][v]){
            if (!cl[v]){
                d[v] = d[u] + c[u][v];
                dfs(v);
                d[v] = 1e9;
            }
        }
        else {
            if (cl[v]){
                flag = 1;
                return;
            }
        }
    }
    cl[u] = 0;
}

int main(){
    faster file
    cin >> ntest;
    while (ntest--){
        cin >> n >> m >> w;
        fi(i, 1, n){
            fi(j, 1, n){
                c[i][j] = 0;
            }
            g[i].clear();
        }
        fi(i, 1, m){
            int u, v, t;
            cin >> u >> v >> t;
            ds(u, v, t);
            ds(v, u, t);
        }
        fi(i, 1, w){
            int u, v, t;
            cin >> u >> v >> t;
            ds(u, v, -t);
        }
        fi(i, 2, n) d[i] = 1e9;
        flag = 0;
        dfs(1);
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
}
