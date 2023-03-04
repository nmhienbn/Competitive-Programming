#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "runcandy"
const int maxn = 2005, mod = 1e9 + 7;
using namespace std;

int n, m, res, root[maxn];
ll mu[maxn];
pii a[maxn];

int get_root(int u){
    return root[u] == 0 ? u : root[u] = get_root(root[u]);
}

bool unify(int u, int v){
    int p = get_root(u);
    int q = get_root(v);
    if (p == q) return false;
    if ((get_root(1) == p && get_root(n) == q) || (get_root(1) == q && get_root(n) == p)) return true;
    root[p] = q;
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    mu[0] = 1;
    fi(i, 1, m - 1) mu[i] = mu[i - 1] * 3 % mod;
    fi(i, 1, m){
        int u, v;
        cin >> u >> v;
        u++;
        v++;
        a[i] = {u, v};
    }
    fid(i, m, 1){
        if (unify(a[i].first, a[i].second)){
            res += mu[i - 1];
            if (res >= mod) res -= mod;
        }
    }
    cout << res;
}
