#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "set"
const int maxn = 50000;
using namespace std;

int n, m, q;
vector<int> g[maxn];
bool cl[maxn];
int res, cnt;

void dfs(int u, int p, int d){
    if (cl[u]){
        if (d < res) res = d, cnt = 1;
        else if (d == res) cnt++;
    }
    for (int v : g[u]) if (v != p && d + 1 <= res){
        dfs(v, u, d + 1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m >> q;
    fi(i, 1, n - 1){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    fi(i, 1, m){
        int x;
        cin >> x;
        cl[x] = 1;
    }
    while (q--){
        int typ, u;
        cin >> typ >> u;
        if (typ == 1){
            cl[u] ^= 1;
        }
        else {
            res = 1e9;
            dfs(u, 0, 0);
            cout << res << ' ' << cnt << '\n';
        }
    }
}
