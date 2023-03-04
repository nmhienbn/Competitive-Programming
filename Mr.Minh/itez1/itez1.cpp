#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "itez1"
const int maxn = 1e5 + 5;
using namespace std;

int n, q, a[maxn];
ll st[maxn << 2], T[maxn << 2];

void build(int id, int l, int r){
    if (l == r){
        st[id] = a[l];
        return;
    }
    int m = (l + r) >> 1;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
    st[id] = max(st[id * 2], st[id * 2 + 1]);
}

void lazy(int id){
    fi(j, id * 2, id * 2 + 1){
        st[j] += T[id];
        T[j] += T[id];
    }
    T[id] = 0;
}

void update(int id, int l, int r, int d, int c, int val){
    if (c < l || d > r || d > c) return;
    if (d <= l && r <= c){
        st[id] += val;
        T[id] += val;
        return;
    }
    if (T[id] != 0) lazy(id);
    int m = (l + r) >> 1;
    update(id * 2, l, m, d, c, val);
    update(id * 2 + 1, m + 1, r, d, c, val);
    st[id] = max(st[id * 2], st[id * 2 + 1]);
}

ll get(int id, int l, int r, int d, int c){
    if (r < d || l > c || d > c) return -1e18;
    if (d <= l && r <= c) return st[id];
    if (T[id] != 0) lazy(id);
    int m = (l + r) >> 1;
    return max(get(id * 2, l, m, d, c), get(id * 2 + 1, m + 1, r, d, c));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i];
    build(1, 1, n);
    cin >> q;
    while (q--){
        int typ, l, r, x;
        cin >> typ >> l >> r;
        if (typ == 1){
            cin >> x;
            update(1, 1, n, l, r, x);
        }
        else {
            cout << get(1, 1, n, l, r) << '\n';
        }
    }
}
