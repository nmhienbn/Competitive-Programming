#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define NunuAndWillump "gss"
const int maxn = 5e4+5, inf = 1e9;

using namespace std;

struct dl {
    int sum, prefix, suffix, best;
};

int n, a[maxn];
dl st[maxn*4];

dl combine(dl l, dl r){
    dl res;
    res.sum = l.sum + r.sum;
    res.prefix = max(l.prefix, l.sum+r.prefix);
    res.suffix = max(r.suffix, r.sum+l.suffix);
    res.best = max({l.best, r.best, l.suffix+r.prefix});
    return res;
}

void build(int id, int l, int r){
    if (l == r){
        st[id].sum = st[id].prefix = st[id].suffix = st[id].best = a[l];
        return;
    }
    int m = (l + r) >> 1;
    build(id*2, l, m);
    build(id*2+1, m+1, r);
    st[id] = combine(st[id*2], st[id*2+1]);
}

dl get(int id, int l, int r, int d, int c){
    if (r < d || l > c) return {0, -inf, -inf, -inf};
    if (d <= l && r <= c) return st[id];
    int m = (l + r) >> 1;
    dl L = get(id*2, l, m, d, c);
    dl R = get(id*2+1, m+1, r, d, c);
    return combine(L, R);
}

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i];
    build(1, 1, n);
    int m;
    cin >> m;
    fi(i, 1, m){
        int l, r;
        cin >> l >> r;
        cout << get(1, 1, n, l, r).best << '\n';
    }
}
