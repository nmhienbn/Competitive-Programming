#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "seqcone"
const int maxn = 1e5 + 5;
using namespace std;

int n, q, a[maxn];

struct dl {
    int ans, lup, ldow, rup, rdow, len;
} st[maxn << 2];

dl combine1(const dl& a, const dl& b){
    dl c;
    c.len = a.len + b.len;
    /*   |/\
         |  \
    */
    if (a.lup == a.len) c.lup = a.len + b.ldow;
    else c.lup = a.lup;
    /*    |
          |\
          | \
    */
    if (a.ldow == a.len) c.ldow = a.len + b.ldow;
    else c.ldow = a.ldow;
    /*    |
         /|
        / |
    */
    c.rup = b.rup;
    /*   /\|
        /  |
    */
    if (b.rdow == b.len && b.ldow == b.len) c.rdow = a.rdow + b.len;
    else c.rdow = b.rdow;

    c.ans = max({a.ans, b.ans, a.rup + b.ldow, a.rdow + b.ldow});
    return c;
}

dl combine2(const dl& a, const dl& b){
    dl c;
    c.len = a.len + b.len;
    /*   |/\
         |  \
    */
    if (a.lup == a.len && a.rup == a.len) c.lup = a.len + b.lup;
    else c.lup = a.lup;
    /*    |
          |\
          | \
    */
    c.ldow = a.ldow;
    /*    |
         /|
        / |
    */
    if (b.rup == b.len) c.rup = a.rup + b.len;
    else c.rup = b.rup;
    /*   /\|
        /  |
    */
    if (b.rdow == b.len) c.rdow = a.rup + b.len;
    else c.rdow = b.rdow;

    c.ans = max({a.ans, b.ans, a.rup + b.ldow, a.rup + b.lup});
    return c;
}

void print(dl x){
    cout << x.ans << ' ' << x.lup << ' ' << x.ldow << ' ' << x.rup << ' ' << x.rdow << '\n';
}

void build(int id, int l, int r){
    st[id].len = r - l + 1;
    if (l == r){
        st[id].ans = st[id].lup = st[id].ldow = st[id].rup = st[id].rdow = 1;
        return;
    }
    int m = (l + r) >> 1;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
    if (a[m] > a[m + 1]) st[id] = combine1(st[id * 2], st[id * 2 + 1]);
    if (a[m] < a[m + 1]) st[id] = combine2(st[id * 2], st[id * 2 + 1]);
}

void update(int id, int l, int r, int vt){
    if (l == r) return;
    int m = (l + r) >> 1;
    if (vt <= m) update(id * 2, l, m, vt);
    else update(id * 2 + 1, m + 1, r, vt);
    if (a[m] > a[m + 1]) st[id] = combine1(st[id * 2], st[id * 2 + 1]);
    if (a[m] < a[m + 1]) st[id] = combine2(st[id * 2], st[id * 2 + 1]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> q;
    fi(i, 1, n) cin >> a[i];
    build(1, 1, n);
    fi(i, 1, q){
        int x, y;
        cin >> x >> y;
        a[x] = y;
        update(1, 1, n, x);
        cout << st[1].ans << '\n';
    }
}
