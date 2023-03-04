#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "itds1"
const int maxn = 1e5 + 5, INF = 1e9 + 1;
using namespace std;

int n, m, a[maxn];
set<pii> st[maxn << 2];

void build(int id, int l, int r){
    fi(i, l, r) st[id].insert({a[i], i});
    if (l == r) return;
    int m = (l + r) >> 1;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
}

void update(int id, int l, int r, int vt, int old, int val){
    st[id].erase({old, vt});
    st[id].insert({val, vt});
    if (l == r) return;
    int m = (l + r) >> 1;
    if (vt <= m) update(id * 2, l, m, vt, old, val);
    else update(id * 2 + 1, m + 1, r, vt, old, val);
}

int get(int id, int l, int r, int d, int c, int val){
    if (r < d || l > c || d > c) return INF;
    if (d <= l && r <= c){
        auto it = st[id].lower_bound({val, d});
        if (it != st[id].end()) return it->first;
        else return INF;
    }
    int m = (l + r) >> 1;
    return min(get(id * 2, l, m, d, c, val),
               get(id * 2 + 1, m + 1, r, d, c, val));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, n) cin >> a[i];
    build(1, 1, n);
    fi(i, 1, m){
        int typ;
        cin >> typ;
        if (typ == 1){
            int v, x;
            cin >> v >> x;
            update(1, 1, n, v, a[v], x);
            a[v] = x;
        }
        else {
            int l, r, x;
            cin >> l >> r >> x;
            int res = get(1, 1, n, l, r, x);
            cout << (res == INF ? -1 : res) << '\n';
        }
    }
}
