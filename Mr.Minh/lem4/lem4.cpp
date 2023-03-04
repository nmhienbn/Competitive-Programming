#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define NunuAndWillump "lem4"
const int maxn = 1e4+5;

using namespace std;

struct dl {
    int l, r, s;
};

int n, m, T[maxn << 3];
dl st[maxn << 3];

dl merge(dl a, int l, int r, dl b, int d, int c){
    dl res;
    res.l = (a.s == r-l+1 ? a.s + b.l : a.l);
    res.r = (b.s == c-d+1 ? b.s + a.r : b.r);
    res.s = max({a.s, b.s, a.r + b.l});
    return res;
}

void build(int id, int l, int r){
    if (l > r) return;
    if (l == r){
        st[id].l = st[id].r = st[id].s = 1;
        return;
    }
    int m = (l + r) >> 1;
    build((id << 1), l, m);
    build((id << 1) | 1, m+1, r);
    st[id] = merge(st[(id << 1)], l, m, st[(id << 1) | 1], m+1, r);
}

void lazy(int id, int l, int r){
    if (!T[id]) return;
    if (T[id] == 1){
        st[id].l = st[id].r = st[id].s = r-l+1;
    }
    else {
        st[id].l = st[id].r = st[id].s = 0;
    }
    T[(id << 1)] = T[(id << 1) | 1] = T[id];
    T[id] = 0;
}

void update(int id, int l, int r, int d, int c, int val){
    if (r < d || l > c) return;
    if (d <= l && r <= c){
        T[id] = val+1;
        lazy(id, l, r);
        return;
    }
    int m = (l+r) >> 1;
    lazy((id << 1), l, m);
    lazy((id << 1) | 1, m+1, r);
    update((id << 1), l, m, d, c, val);
    update((id << 1) | 1, m+1, r, d, c, val);
    st[id] = merge(st[(id << 1)], l, m, st[(id << 1) | 1], m+1, r);
}

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n >> m;
    build(1, 1, n);
    while (m--){
        int typ, l, r;
        cin >> typ;
        if (typ != 3){
            cin >> l >> r;
            update(1, 1, n, l, r, typ-1);
        }
        else {
            cout << st[1].s << '\n';
        }
    }

}
