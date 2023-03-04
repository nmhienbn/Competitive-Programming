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

struct dl {
    int l, r, s, len, lz = -1;
} a[maxn * 6];

void build(int id, int l, int r){
    a[id].l = a[id].r = a[id].len = a[id].s = r - l + 1;
    if (l == r) return;
    int m = (l + r) >> 1;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
}

void combine(dl& c, dl a, dl b){
    c.s = max({a.s, b.s, a.r + b.l});
    if (a.l == a.len) c.l = a.l + b.l;
    else c.l = a.l;
    if (b.r == b.len) c.r = b.r + a.r;
    else c.r = b.r;
}

void lazy(int id, int val){
    a[id].l = a[id].r = a[id].s = val * a[id].len;
    a[id].lz = val;
}

void down(int id){
    if (a[id].lz >= 0){
        lazy(id * 2, a[id].lz);
        lazy(id * 2 + 1, a[id].lz);
        a[id].lz = -1;
    }
}

void update(int id, int l, int r, int d, int c, int val){
    if (r < d || l > c || l > r) return;
    if (d <= l && r <= c){
        lazy(id, val);
        return;
    }
    down(id);
    int m = (l + r) >> 1;
    update(id * 2, l, m, d, c, val);
    update(id * 2 + 1, m + 1, r, d, c, val);
    combine(a[id], a[id * 2], a[id * 2 + 1]);
}

int get(int id, int l, int r, int val, bool flag){
    if (a[id].len < val) return -1;
    if (a[id].len == val) return l;
    int m = (l + r) >> 1;
    down(id);
    if (flag){
        if (a[id * 2 + 1].r >= val) return get(id * 2 + 1, m + 1, r, val, 1);
        return get(id * 2, l, m, a[id * 2].r, 1);
    }
    if (a[id * 2].s >= val) return get(id * 2, l, m, val, 0);
    if (a[id * 2].r + a[id * 2 + 1].l >= val) return get(id * 2, l, m, a[id * 2].r, 1);
    return get(id * 2 + 1, m + 1, r, val, 0);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> q;
    build(1, 1, n);
    fi(i, 1, q){
        char typ;
        cin >> typ;
        if (typ == 'A'){
            int p;
            cin >> p;
            if (a[1].s < p) res++;
            else {
                int vt = get(1, 1, n, p, 0);
                update(1, 1, n, vt, vt + p - 1, 0);
            }
        }
        else {
            int l, r;
            cin >> l >> r;
            update(1, 1, n, l, r, 1);
        }
    }
    cout << res;
}
