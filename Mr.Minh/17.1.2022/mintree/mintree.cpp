#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "mintree"
const int maxn = 1e5 + 5;
using namespace std;

struct dl {
    int u, v, w;
    bool operator < (const dl& x) const {
        return w < x.w;
    }
};

int n, m, lab[maxn];
dl a[maxn];
int b[maxn], cnt, res;

int find(int u){
    return lab[u] < 0 ? u : lab[u] = find(lab[u]);
}

bool unify(int u, int v){
    int p = find(u);
    int q = find(v);
    if (p == q) return false;
    if (lab[p] < lab[q]) swap(p, q);
    lab[q] += lab[p];
    lab[p] = q;
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, m){
        int u, v, w;
        cin >> u >> v >> w;
        a[i] = {u, v, w};
    }
    sort(a + 1, a + m + 1);
    fi(i, 0, n) lab[i] = -1;
    fi(i, 1, m) if (unify(a[i].u, a[i].v)){
        res += a[i].w;
        b[++cnt] = i;
    }
    cout << res << '\n';
    fi(i, 1, cnt){
        cout << a[b[i]].u << ' ' << a[b[i]].v << '\n';
    }
}
