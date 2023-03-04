#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "library"
const int maxn = 1e5 + 5;
using namespace std;

int n, m;
int a[maxn], mina;
ll res;
bool cl[maxn];
vector<int> g[maxn];

void dfs(int u){
    cl[u] = 1;
    mina = min(mina, a[u]);
    for (int v : g[u]) if (!cl[v]){
        dfs(v);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, n)
        cin >> a[i];
    fi(i, 1, m){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    fi(i, 1, n) if (!cl[i]){
        mina = 1e9;
        dfs(i);
        res += mina;
    }
    cout << res;
}
