#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "votree"
const int maxn = 7e4 + 5;
using namespace std;

int n, m, in[maxn], out[maxn], lg2[maxn], b[maxn][20],
    L[maxn][20], M[maxn][20], id, vt[maxn], h[maxn];
vector<int> g[maxn];

void dfs(int u, int p){
    in[u] = ++id;
    vt[id] = u;
    for (int v : g[u]){
        if (v == p) continue;
        h[v] = h[u] + 1;
        b[v][0] = u;
        fi(i, 1, 16) b[v][i] = b[b[v][i - 1]][i - 1];
        dfs(v, u);
    }
    out[u] = id;
}

int LCA(int u, int v){
    if (h[u] < h[v]) swap(u, v);
    int del = h[u] - h[v];
    fid(i, 16, 0) if (gb(del, i)){
        u = b[u][i];
    }
    if (u == v) return u;
    fid(i, 16, 0) if (b[u][i] != b[v][i]){
        u = b[u][i];
        v = b[v][i];
    }
    return b[u][0];
}

int getMin(int l, int r){
    int t = lg2[r - l + 1];
    return min(L[l][t], L[r + 1 - (1 << t)][t]);
}

int getMax(int l, int r){
    int t = lg2[r - l + 1];
    return max(M[l][t], M[r + 1 - (1 << t)][t]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    fi(i, 2, n){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1, 0);
    fi(i, 2, n) lg2[i] = lg2[i >> 1] + 1;
    fi(i, 1, n) L[i][0] = M[i][0] = in[i];
    fi(j, 1, lg2[n]){
        fi(i, 1, n + 1 - (1 << j)){
            L[i][j] = min(L[i][j - 1], L[i + (1 << (j - 1))][j - 1]);
            M[i][j] = max(M[i][j - 1], M[i + (1 << (j - 1))][j - 1]);
        }
    }
    while (m--){
        int u, v;
        cin >> u >> v;
        cout << LCA(vt[getMin(u, v)], vt[getMax(u, v)]) << '\n';
    }
}
