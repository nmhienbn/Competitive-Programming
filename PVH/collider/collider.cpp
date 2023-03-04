#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define gt(a) lower_bound(val.begin(), val.end(), a) - val.begin() + 1
#define pb push_back
#define ll long long
#define Irelia "collider"
const int maxn = 2e5 + 5;
using namespace std;

struct dl {
    int t, f, s, id;
    bool operator < (const dl& x) const {
        return t < x.t;
    }
};

int sub, m, n, vt;
dl a[maxn], b[maxn], ad[maxn * 2];
int st[maxn << 2];
vector<int> val;

void update(int id, int l, int r, int vt, int x){
    if (l == r){
        st[id] += x;
        return;
    }
    int m = (l + r) >> 1;
    if (l <= m) update(id << 1, l, m, vt, x);
    else update(id << 1 | 1, m + 1, r, vt, x);
    st[id] = max(st[id << 1], st[id << 1 | 1]);
}
int get(int id, int l, int r, int d, int c){
    if (r < d || l > c) return 0;
    if (d <= l && r <= c) return st[id];
    int m = (l + r) >> 1;
    return max(get(id << 1, l, m, d, c), get(id << 1 | 1, m + 1, r, d, c));
}

void update(int vt, int x){
    if (vt <= val.size()) update(1, 1, val.size(), vt, x);
}
int get(int d, int c){
    if (d <= c) return get(1, 1, val.size(), d, c);
    return 0;
}

int check(int g){
    int q = 0;
    fi(i, 1, m){
        if (a[i].f + g <= a[i].s - g){
            ad[++q] = {a[i].f + g, a[i].t, 1, i};
            ad[++q] = {a[i].s - g + 1, a[i].t, -1, i};
        }
    }
    if (!q) return 0;
    sort(ad + 1, ad + q + 1);
    fi(i, 1, q) cout << ad[i].f << ' ';
    int j = 1;
    fi(i, 1, n){
        while (j <= q && ad[j].t <= b[i].t) update(ad[j].f, ad[j].s), j++;
        if (b[i].f + g <= b[i].s - g && get(gt(b[i].f + g), gt(b[i].s - g))){
            while (j <= q) update(ad[j].f, ad[j].s), j++;
            return b[i].id;
        }
        cout << gt(b[i].f + g) << ' ' << gt(b[i].s - g) << '\n';
    }
    while (j <= q) update(ad[j].f, ad[j].s), j++;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> sub >> m >> n;
    fi(i, 1, m) cin >> a[i].t >> a[i].f >> a[i].s;
    fi(i, 1, m) val.pb(a[i].t);
    sort(val.begin(), val.end());
    val.resize(unique(val.begin(), val.end()) - val.begin());
    fi(i, 1, n) a[i].t = gt(a[i].t);
    fi(i, 1, n) cin >> b[i].t >> b[i].f >> b[i].s, b[i].id = i;
    sort(b + 1, b + n + 1);
    int d = 1, c = 2e9;
    check(2);
//    while (d <= c){
//        int g = (d + c) >> 1;
//        int tmp = check(g);
//        if (tmp) vt = tmp, d = g + 1;
//        else c = g - 1;
//    }
    cout << c << '\n';

}
