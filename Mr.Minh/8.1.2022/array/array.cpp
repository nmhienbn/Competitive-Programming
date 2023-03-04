#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "array"
const int maxn = 1e5 + 5, INF = 1e9;
using namespace std;

struct dl {
    int f, s;
    void operator += (int x){
        f += x;
        s += x;
        return;
    }
    bool operator < (const dl& x) const {
        return f == x.f ? s > x.s : f > x.f;
    }
} st[maxn];

int n, s, q, a[maxn], b[maxn], kt3, sa[maxn], sb[maxn];
bool kta = 1, ktb = 1;
int len[maxn << 2], lz[maxn << 2];

struct query {
    int t, i, x, y;
} Q[maxn];

dl combine(dl a, dl b){
    dl c;
    c.f = min(a.f, b.f);
    c.s = max(a.s, b.s);
    return c;
}

void build(int id, int l, int r, int a[]){
    len[id] = r - l + 1;
    if (l == r){
        st[id] = {a[l], a[l]};
        return;
    }
    int m = (l + r) >> 1;
    build(id * 2, l, m, a);
    build(id * 2+ 1, m + 1, r, a);
    st[id] = combine(st[id * 2], st[id * 2 + 1]);
}

void lazy(int id, int val){
    st[id] += len[id] * val;
    lz[id] += val;
}

void down(int id){
    lazy(id * 2, lz[id]);
    lazy(id * 2 + 1, lz[id]);
    lz[id] = 0;
}

void update(int id, int l, int r, int d, int c, int val){
    if (r < d || l > c || d > c) return;
    if (d <= l && r <= c){
        lazy(id, val);
        return;
    }
    down(id);
    int m = (l + r) >> 1;
    update(id * 2, l, m, d, c, val);
    update(id * 2 + 1, m + 1, r, d, c, val);
    st[id] = combine(st[id * 2], st[id * 2 + 1]);
}

int get(int id, int l, int r, int d, int c){
    if (r < d || l > c || d > c) return -INF;
    if (d <= l && r <= c) return st[id].s;
    int m = (l + r) >> 1;
    down(id);
    return max(get(id * 2, l, m, d, c), get(id * 2 + 1, m + 1, r, d, c));
}
int get(int id, int l, int r, int vt){
    if (vt < l || vt > r) return -INF;
    if (l == r) return st[id].s;
    int m = (l + r) >> 1;
    down(id);
    if (vt <= m) return get(id * 2, l, m, vt);
    else return get(id * 2 + 1, m + 1, r, vt);
}

int get(int id, int l, int r, int d, int c, int val){
    if (r < d || l > c || d > c || st[id].f > val) return -1;
    if (l == r) return r;
    int m = (l + r) >> 1;
    down(id);
    if (st[id * 2 + 1].f <= val) return get(id * 2 + 1, m + 1, r, d, c, val);
    return get(id * 2, l, m, d, c, val);
}

void sub1(){
    build(1, 0, n, sb);
    fi(i, 1, q){
        if (Q[i].t == 1){
            update(1, 0, n, Q[i].i, n, Q[i].y - b[Q[i].i]);
            b[Q[i].i] = Q[i].y;
        }
        else {
            if (s > Q[i].i) cout << -1 << '\n';
            else cout << get(1, 0, n, Q[i].i) - get(1, 0, n, 0, min(Q[i].i - 1, Q[i].i - s)) << '\n';
        }
    }
    exit(0);
}

void sub2(){
    build(1, 0, n, sa);
    fi(i, 1, q){
        if (Q[i].t == 1){
            update(1, 0, n, Q[i].i, n, Q[i].x - a[Q[i].i]);
            a[Q[i].i] = Q[i].x;
        }
        else {
            int vt = get(1, 0, n, 0, Q[i].i - 1, get(1, 0, n, Q[i].i) - s);
            if (vt == -1) cout << -1 << '\n';
            else cout << Q[i].i - vt << '\n';
        }
    }
    exit(0);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> s;
    fi(i, 1, n){
        cin >> a[i];
        if (a[i] != 1) kta = 0;
        sa[i] = sa[i - 1] + a[i];
    }
    fi(i, 1, n){
        cin >> b[i];
        if (b[i] != 1) ktb = 0;
        sb[i] = sb[i - 1] + b[i];
    }
    cin >> q;
    fi(i, 1, q){
        cin >> Q[i].t;
        if (Q[i].t == 1){
            cin >> Q[i].i >> Q[i].x >> Q[i].y;
            if (Q[i].x != 1) kta = 0;
            if (Q[i].y != 1) ktb = 0;
        }
        else {
            cin >> Q[i].i;
        }
    }
    if (kta) sub1();
    if (ktb) sub2();
}
