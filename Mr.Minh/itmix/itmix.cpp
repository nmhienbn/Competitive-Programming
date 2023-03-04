#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "itmix"
const int maxn = 1e5 + 5, mod = 1e9 + 7;
using namespace std;

int n, q, a[maxn];

struct node {
    int val, mul = 1, add, ass, num;
} st[maxn << 2];

void clr(int id){
    st[id].ass = st[id].add = 0;
    st[id].mul = 1;
}

int cong(int x, int y){
    x += y;
    if (x >= mod) return x - mod;
    return x;
}

void build(int id, int l, int r){
    st[id].num = r - l + 1;
    if (l == r){
        st[id].val = a[l];
        return;
    }
    int m = (l + r) >> 1;
    build(id << 1, l, m);
    build(id << 1 | 1, m + 1, r);
    st[id].val = cong(st[id << 1].val, st[id << 1 | 1].val);
}

void lazy(int id, int mul, int add, int ass){
    if (ass != 0){
        clr(id);
        st[id].ass = ass;
        st[id].val = (1ll * ass * st[id].num) % mod;
        return;
    }
    if (st[id].ass != 0){
        st[id].ass = (1ll * st[id].ass * mul + add) % mod;
        st[id].val = (1ll * st[id].ass * st[id].num) % mod;
        return;
    }
    st[id].mul = (1ll * st[id].mul * mul) % mod;
    st[id].add = (1ll * st[id].add * mul + add) % mod;
    st[id].val = (1ll * st[id].val * mul + 1ll * add * st[id].num) % mod;
}

void down(int id){
    lazy(id << 1, st[id].mul, st[id].add, st[id].ass);
    lazy(id << 1 | 1, st[id].mul, st[id].add, st[id].ass);
    clr(id);
}

void update(int id, int l, int r, int u, int v, int mul, int add, int ass){
    if (u > r || l > v) return;
    if (u <= l && r <= v){
        lazy(id, mul, add, ass);
        return;
    }
    down(id);
    int m = (l + r) >> 1;
    update(id << 1, l, m, u, v, mul, add, ass);
    update(id << 1 | 1, m + 1, r, u, v, mul, add, ass);
    st[id].val = cong(st[id << 1].val, st[id << 1 | 1].val);
}

int get(int id, int l, int r, int u, int v){
    if (u > r || l > v) return 0;
    if (u <= l && r <= v) return st[id].val;
    down(id);
    int m = (l + r) >> 1;
    return cong(get(id << 1, l, m, u, v),
                get(id << 1 | 1, m + 1, r, u, v));
}

int c, l, r, x;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    build(1, 1, n);
    while (q--){
        cin >> c >> l >> r;
        if (c != 4) cin >> x;
        if (c == 1) update(1, 1, n, l, r, 1, x, 0);
        else if (c == 2) update(1, 1, n, l, r, x, 0, 0);
        else if (c == 3) update(1, 1, n, l, r, 1, 0, x);
        else cout << get(1, 1, n, l, r) << "\n";
    }
}
