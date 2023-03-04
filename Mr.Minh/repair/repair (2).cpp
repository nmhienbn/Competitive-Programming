#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "repair"
const int maxn = 1e5 + 5;

using namespace std;

struct dl {
    int u, v, w;
    bool operator < (const dl& x) const {
        return w == x.w ? (u == x.u ? v < x.v : u < x.u) : w < x.w;
    }
} E[maxn];

int n, m, a[maxn], root[maxn], k;
ll len;
pii res[maxn];

int get(int u){
    return root[u] == 0 ? u : root[u] = get(root[u]);
}

bool unify(int u, int v){
    int p = get(u);
    int q = get(v);
    if (p == q) return false;
    root[q] = p;
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, n) cin >> a[i];
    fi(i, 1, m){
        int u, v, w;
        cin >> u >> v >> w;
        if (u > v) swap(u, v);
        if (a[u] > a[v]) E[i] = {u, v, a[u] * (w / 2) + a[v] * (w - w / 2)};
        else E[i] = {u, v, a[v] * (w / 2) + a[u] * (w - w / 2)};
    }
    sort(E + 1, E + m + 1);
    fi(i, 1, m){
        if (unify(E[i].u, E[i].v)){
            len += E[i].w;
            res[++k] = {E[i].u, E[i].v};
        }
    }
    sort(res + 1, res + k + 1);
    cout << len << '\n';
    fi(i, 1, k) cout << res[i].first << ' ' << res[i].second << '\n';
}
