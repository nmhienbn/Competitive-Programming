#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "sunbathe"
const int maxn = 5e5 + 5;
using namespace std;

int n, q, res;
int lz[maxn << 2];
struct dl {
    int l, r, mid, ans, len;
    void rs(int x){
        l = r = mid = ans = x;
    }
} st[maxn << 2];

void build(int id, int l, int r){
    st[id].len = r - l + 1;
    st[id].rs(st[id].len);
    lz[id] = -1;
    if (l == r) return;
    int m = (l + r) >> 1;
    build(id << 1, l, m);
    build(id << 1 | 1, m + 1, r);
}
void Merge(dl& res, dl& a, dl& b){
    res.l = a.l;
    if (a.l == a.len) res.l += b.l;
    res.r = b.r;
    if (b.r == b.len) res.r += a.r;
    res.mid = a.r + b.l;
    res.ans = max({res.mid, a.ans, b.ans});
}
void lazy(int id, int x){
    if (x) st[id].rs(st[id].len);
    else st[id].rs(0);
    lz[id] = x;
}
void down(int id){
    if (lz[id] == -1) return;
    lazy(id << 1, lz[id]);
    lazy(id << 1 | 1, lz[id]);
    lz[id] = -1;
}
void update(int id, int l, int r, int d, int c, int x){
    if (r < d || l > c) return;
    if (d <= l && r <= c){
        lazy(id, x);
        return;
    }
    int m = (l + r) >> 1;
    down(id);
    update(id << 1, l, m, d, c, x);
    update(id << 1 | 1, m + 1, r, d, c, x);
    Merge(st[id], st[id << 1], st[id << 1 | 1]);
}
void update(int l, int r, int x){
    if (l <= r) update(1, 1, n, l, r, x);
}
int get(int id, int l, int r, int p, bool flag){
    if (st[id].ans < p) return -1;
    if (st[id].len == p) return l;
    int m = (l + r) >> 1;
    down(id);
    if (!flag){
        if (st[id << 1].ans >= p) return get(id << 1, l, m, p, 0);
        if (st[id].mid >= p) return get(id << 1, l, m, st[id << 1].r, 1);
        //else if (st[id << 1 | 1].ans >= p)
        return get(id << 1 | 1, m + 1, r, p, 0);
    }
    else {
        if (st[id << 1 | 1].r >= p) return get(id << 1 | 1, m + 1, r, p, 1);
        return get(id << 1, l, m, p - st[id << 1 | 1].len, 1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> q;
    build(1, 1, n);
    fi(rep, 1, q){
        char typ;
        cin >> typ;
        if (typ == 'A'){
            int p;
            cin >> p;
            int vt = get(1, 1, n, p, 0);
            if (~vt) update(vt, vt + p - 1, 0);
            else res++;
        }
        else {
            int l, r;
            cin >> l >> r;
            update(l, r, 1);
        }
    }
    cout << res;
}
