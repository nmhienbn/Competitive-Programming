#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL);
#define NunuAndWillump "pw"
const int maxn = 1e5+5;

using namespace std;

struct dl {
    int a, b, c, val;
    bool operator < (const dl& x) const {
        return a != x.a ? a < x.a : val < x.val;
    }
};

int n, m, k, T[maxn << 2], res;
dl a[maxn << 1];
pii st[maxn << 2], vt;

pii merge(pii a, pii b){
    if (a.first >= b.first) return a;
    return b;
}

void lazy(int id){
    fi(i, id*2, id*2+1){
        T[i] += T[id];
        st[i].first += T[id];
    }
    T[id] = 0;
}

void build(int id, int l, int r){
    if (l == r){
        st[id].second = l;
        return;
    }
    int m = (l+r) >> 1;
    build(id*2, l, m);
    build(id*2+1, m+1, r);
    st[id] = merge(st[id*2], st[id*2+1]);
}

void update(int id, int l, int r, int d, int c, int val){
    if (r < d || l > c) return;
    if (d <= l && r <= c){
        st[id].first += val;
        T[id] += val;
        return;
    }
    int m = (l+r) >> 1;
    lazy(id);
    update(id*2, l, m, d, c, val);
    update(id*2+1, m+1, r, d, c, val);
    st[id] = merge(st[id*2], st[id*2+1]);
}
//
//int get(int id, int l, int r, int d, int c){
//    if (r < d || l > c) return 0;
//    if (d <= l && r <= c) return st[id];
//    int m = (l + r) >> 1;
//    return max(get(id*2, l, m, d, c), get(id*2+1, m+1, r, d, c));
//}

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n >> m >> k;
    fi(i, 1, m){
        int x, y, z, t;
        cin >> x >> y >> z >> t;
        a[i] = {x, y, t+k-1, 1};
        a[i+m] = {z+k, y, t+k-1, -1};
    }
    m += m;
    build(1, 1, n);
    sort(a+1, a+m+1);
    fi(i, 1, m){
        update(1, 1, n, a[i].b, a[i].c, a[i].val);
        if (res < st[1].first){
            res = st[1].first;
            vt = {max(a[i].a - k + 1, 1), max(st[1].second - k + 1, 1)};
        }
    }
    cout << res << '\n' << vt.first << ' ' << vt.second;
}
