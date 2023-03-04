#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "colorful"
const int maxn = 2e6+5;
using namespace std;

int sub, n, c[maxn], root[maxn], deg[maxn], stp;
vector<int> g[maxn];
bool flag;

int get_root(int u){
    return root[u] == 0 ? u : root[u] = get_root(root[u]);
}

void dfs(int u, int par){
    for (int v : g[u]){
        if (v == par) continue;
        if (c[v] == c[u]){
            root[v] = u;
            stp--;
        }
        else {
            deg[u]++;
            deg[v]++;
        }
        dfs(v, u);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> sub >> n;
    stp = n;
    fi(i, 1, n-1){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    fi(i, 1, n) cin >> c[i];
    dfs(1, 0);
    if (stp == 1){
        cout << "YES\n";
        fi(i, 1, n){
            cout << i << ' ';
        }
        exit(0);
    }
    fi(i, 1, n){
        if (deg[i] >= stp-1){
            if (!flag) flag = 1, cout << "YES\n" << i << ' ';
            else cout << i << ' ';
        }
    }
    if (!flag) cout << "NO";
}
