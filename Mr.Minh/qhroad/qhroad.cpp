#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "qhroad"
const int maxn = 1e5+5;

using namespace std;

int n, m, q, res[maxn], t[maxn];
bool kt[maxn];
pii E[maxn];

int root[maxn];
int get_root(int u){
    return root[u] > 0 ? root[u] = get_root(root[u]) : u;
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
    cin >> n >> m >> q;
    fi(i, 1, m){
        int u, v;
        cin >> u >> v;
        E[i] = {u, v};
    }
    fi(i, 1, q){
        int id;
        cin >> id;
        kt[id] = 1;
        t[i] = id;
    }
    int cnt = n;
    fi(i, 1, m) if (!kt[i]){
        int u = E[i].first, v = E[i].second;
        if (unify(u, v)) cnt--;
    }
    fid(i, q, 1){
        int u = E[t[i]].first, v = E[t[i]].second;
        res[i] = cnt;
        if (unify(u, v)) cnt--;
    }
    fi(i, 1, q) cout << res[i] << '\n';
}
