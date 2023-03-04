#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "itteq1"
const int maxn = 3e5 + 5;
using namespace std;

int n, q, T[maxn << 2];
string s;

struct dl {
    int l, r, len;
    ll res;
} st[maxn << 2];

dl combine(dl a, dl b){
    dl c;
    c.len = a.len + b.len;
    c.l = a.l;
    if (a.l == a.len) c.l += b.l;
    c.r = b.r;
    if (b.r == b.len) c.r += a.r;
    c.res = a.res + b.res + 1ll * a.r * b.l;
    //cout << c.res << ' ';
    return c;
}

void clr(dl& a){
    //a.l = a.r = a.res = 0;
}

void full(dl& a){
    a.l = a.r = a.len;
    a.res = 1ll * a.len * (a.len + 1) / 2;
}

void build(int id, int l, int r){
    if (l == r){
        st[id].res = st[id].l = st[id].r = s[l - 1] - '0';
        st[id].len = 1;
        return;
    }
    int m = (l + r) >> 1;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
    st[id] = combine(st[id * 2], st[id * 2 + 1]);
    //cout << l << ' ' << r << ' ' << st[id].res << '\n';
}

void lazy(int id){
    if (T[id] == -1) return;
    if (T[id] == 0){
        clr(st[id * 2]);
        clr(st[id * 2 + 1]);
    }
    else {
        full(st[id * 2]);
        full(st[id * 2 + 1]);
    }
    T[id * 2] = T[id * 2 + 1] = T[id];
    T[id] = -1;
}

void update(int id, int l, int r, int d, int c, int x){
    if (r < d || l > c || d > c) return;
    if (d <= l && r <= c){
        if (x == 0) clr(st[id]);
        else full(st[id]);
        T[id] = x;
        //cout << l << ' ' << r << ' ' << st[id].res << '\n';
        return;
    }
    int m = (l + r) >> 1;
    lazy(id);
    update(id * 2, l, m, d, c, x);
    update(id * 2 + 1, m + 1, r, d, c, x);
    st[id] = combine(st[id * 2], st[id * 2 + 1]);
    //cout << l << ' ' << r << ' ' << st[id].res << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    memset(T, -1, sizeof T);
    cin >> n >> q >> s;
    build(1, 1, n);
    cout << st[1].res << '\n';
    while (q--){
        int l, r, x;
        cin >> l >> r >> x;
        update(1, 1, n, l, r, x);
        cout << st[1].res << '\n';
    }
}
