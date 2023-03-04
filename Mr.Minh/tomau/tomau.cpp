#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "tomau"
const int maxn = 5e4+5;
using namespace std;

struct node {
    int l, r, s;
} st[maxn*16];

int n, q, T[maxn];

void lazy(int id, int l, int m, int r){
    if (!T[id]) return;
    T[id*2] = T[id*2+1] = T[id];
    st[id*2].l = st[id*2].r = st[id*2].s = (T[id]-1)*(m-l+1);
    st[id*2+1].l = st[id*2+1].r = st[id*2+1].s = (T[id]-1)*(r-m);
    T[id] = 0;
}

node merge(node a, node b){
    node res;
    res.l = (a.l == a.s) ? a.s+b.l : max(a.l, 0);
    res.r = (b.r == b.s) ? b.s+max(a.r, 0) : b.r;
    res.s = max({a.s, b.s, a.r+b.l});
    return res;
}

void build(int id, int l, int r){
    if (l == r){
        st[id].l = st[id].r = st[id].s = 1;
        return;
    }
    int m = (l+r) >> 1;
    build(id*2, l, m);
    build(id*2+1, m+1, r);
    st[id].l = st[id].r = st[id].s = r-l+1;
}

void update(int id, int l, int r, int d, int c, int val){
    if (r < d || l > c) return;
    if (d <= l && r <= c){
        st[id].l = st[id].r = st[id].s = val*(r-l+1);
        T[id] = val+1;
        return;
    }
    int m = (l+r) >> 1;
    lazy(id, l, m, r);
    update(id*2, l, m, d, c, val);
    update(id*2+1, m+1, r, d, c, val);
    st[id] = merge(st[id*2], st[id*2+1]);
}

node get(int id, int l, int r, int d, int c){
    if (r < d || l > c) return {0, 0, 0};
    if (d <= l && r <= c) return st[id];
    int m = (l+r) >> 1;
    lazy(id, l, m, r);
    return merge(get(id*2, l, m, d, c), get(id*2+1, m+1, r, d, c));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> q;
    build(1, 1, n);
    while (q--){
        int typ, x, y;
        cin >> typ >> x;
        if (typ == 2){
            cin >> y;
            update(1, 1, n, x, x+y-1, 1);
        }
        else {
            if (get(1, 1, n, 1, n).s < x){
                cout << "0\n";
                continue;
            }
            int d = x, c = n;
            while (d <= c){
                int g = (d + c) >> 1;
                node now = get(1, 1, n, 1, g);
                if (now.s >= x) c = g-1;
                else d = g+1;
            }
            cout << d-x+1 << '\n';
            update(1, 1, n, d-x+1, d, 0);
        }
    }
}
