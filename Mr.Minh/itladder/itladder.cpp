#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "itladder"
const int maxn = 1e5 + 5, mod = 1e9 + 7;
const ll M = 1ll * mod * mod;
using namespace std;

int n, q, st[maxn << 2];
struct dl {
    int f, s, len, sum;
} T[maxn << 2];

void build(int id, int l, int r){
    T[id].len = r - l + 1;
    if (l == r){
        T[id].sum = l;
        return;
    }
    int m = (l + r) >> 1;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
    T[id].sum = T[id * 2].sum + T[id * 2 + 1].sum;
}

void add(int& x, int y){
    x += y;
    if (x >= mod) x -= mod;
}

int cong(int x, int y){
    x += y;
    if (x >= mod) return x - mod;
    return x;
}

void lazy(int id){
    fi(j, id * 2, id * 2 + 1){
        st[j] = (st[j] + 1ll * T[id].f * T[j].sum + 1ll * T[id].s * T[j].len) % mod;
        add(T[j].f, T[id].f);
        add(T[j].s, T[id].s);
    }
    T[id].f = T[id].s = 0;
}

void update(int id, int l, int r, int d, int c, int x, int y){
    if (r < d || l > c || d > c) return;
    if (d <= l && r <= c){
        st[id] = (st[id] + 1ll * x * T[id].sum + 1ll * y * T[id].len) % mod;
        add(T[id].f, x);
        add(T[id].s, y);
        return;
    }
    int m = (l + r) >> 1;
    lazy(id);
    update(id * 2, l, m, d, c, x, y);
    update(id * 2 + 1, m + 1, r, d, c, x, y);
    st[id] = cong(st[id * 2], st[id * 2 + 1]);
}

int get(int id, int l, int r, int d, int c){
    if (r < d || l > c || d > c) return 0;
    if (d <= l && r <= c) return st[id];
    int m = (l + r) >> 1;
    lazy(id);
    return cong(get(id * 2, l, m, d, c),
                get(id * 2 + 1, m + 1, r, d, c));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> q;
    build(1, 1, n);
    while (q--){
        int typ, l, r, a, b;
        cin >> typ >> l >> r;
        if (typ == 1){
            cin >> a >> b;
            update(1, 1, n, l, r, a, (b - 1ll * a * l + M) % mod);
        }
        else {
            cout << get(1, 1, n, l, r) << '\n';
        }
    }
}
