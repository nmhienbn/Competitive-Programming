#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Ahri "nkcity"
const int maxn = 1e5+5;

using namespace std;

struct edge{
    int u, v, w;
    operator < (const edge& x) const{
        return w < x.w;
    }
};

int n, m, root[maxn];
ll res;
edge E[maxn];

int getRoot(int u){
    return root[u] ? root[u] = getRoot(root[u]) : u;
}

bool unify(int u, int v){
    int p = getRoot(u);
    int q = getRoot(v);
    if (p == q) return 0;
    root[p] = q;
    return 1;
}

int main(){
    faster
    freopen(Ahri".inp", "r", stdin);
    freopen(Ahri".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, m){
        int u, v, w;
        cin >> u >> v >> w;
        E[i] = {u, v, w};
        res += w;
    }
    sort(E+1, E+m+1);
    fi(i, 1, m){
        if (unify(E[i].u, E[i].v)){
            res = E[i].w;
        }
    }
    cout << res << '\n';
}
