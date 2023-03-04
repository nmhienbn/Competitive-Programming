#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "cheer"
const int maxn = 1e4+5;

using namespace std;

struct dl {
    int u, v, w;
    bool operator < (const dl& x) const {
        return w < x.w;
    }
} E[maxn];

int n, m, c[maxn], minc = 1e9, res, root[maxn];

int get_root(int u){
    return root[u] == 0 ? u : root[u] = get_root(root[u]);
}

bool unify(int u, int v){
    int p = get_root(u);
    int q = get_root(v);
    if (p == q) return 0;
    root[p] = q;
    return 1;
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, n) cin >> c[i], minc = min(minc, c[i]);
    fi(i, 1, m){
        int u, v, w;
        cin >> u >> v >> w;
        w = w*2 + c[u] + c[v];
        E[i] = {u, v, w};
    }
    sort(E+1, E+m+1);
    fi(i, 1, m){
        int u = E[i].u, v = E[i].v, w = E[i].w;
        if (unify(u, v)){
            res += w;
        }
    }
    cout << res + minc;
}
