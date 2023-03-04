#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL);
#define NunuAndWillump "beatiset"
const int maxn = 5e4+5;

using namespace std;

int n, q, a[maxn], b[maxn][20], h[maxn],
    color[maxn], child[maxn];
vector<int> g[maxn], cl[maxn];

void dfs(int u){
    child[u] = 1;
    for (auto v : g[u]){
        if (v != b[u][0]){
            b[v][0] = u;
            h[v] = h[u]+1;
            fi(i, 1, 17) b[v][i] = b[b[v][i-1]][i-1];
            dfs(v);
            child[u] += child[v];
        }
    }
}

int LCA(int u, int v){
    if (h[u] < h[v]) swap(u, v);
    int del = h[u] - h[v];
    fid(i, 17, 0){
        if ((del >> i) & 1){
            u = b[u][i];
        }
    }
    if (u == v) return u;
    fid(i, 17, 0){
        if (b[u][i] != b[v][i]){
            u = b[u][i];
            v = b[v][i];
        }
    }
    return b[u][0];
}

void case1(int u){
    if (child[u] <= T){

    }
}

int main(){
    faster
    //freopen(NunuAndWillump".inp", "r", stdin);
    //freopen(NunuAndWillump".out", "w", stdout);
    cin >> n >> q;
    fi(i, 1, n){
        cin >> color[i];
        cl[color[i]].pb(i);
    }
    fi(i, 1, n-1){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1);
    int n2 = sqrt(n);
    int T = n2 * 2;
    while(q--){
        int typ, u, v;
        cin >> typ >> u;
        if (typ == 1){
            case1(u);
        }
        else if (typ == 2){
            case2(u);
        }
        else {
            cin >> v;
            case3(u, v);
        }
    }
}
