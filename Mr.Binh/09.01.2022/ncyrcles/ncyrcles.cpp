//Euler Characteristics Solution: Vertices - Edges + Faces = 1 + (Number of Connected Components)

#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pb push_back
#define ll long long
#define Irelia "ncyrcles"
const int maxn = 3e5 + 5;
using namespace std;

struct pii {
    int f, s;
};

int n, V, E, F, t, stp;
unordered_map<int, int> gt;
vector<int> g[maxn];
bool cl[maxn];

void dfs(int u){
    cl[u] = 1;
    for (int v : g[u]){
        if (!cl[v]) dfs(v);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        int r, x, u, v;
        cin >> x >> r;
        if (!gt[x - r]) gt[x - r] = ++V;
        if (!gt[x + r]) gt[x + r] = ++V;
        u = gt[x - r];
        v = gt[x + r];
        g[u].pb(v);
        g[v].pb(u);
    }
    fi(i, 1, V) if (!cl[i]){
        stp++;
        dfs(i);
    }
    E = n * 2;
    cout << 1 + stp - V + E;
}
