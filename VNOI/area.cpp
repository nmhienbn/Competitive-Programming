#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "area"
const int maxn = 4e5 + 5;
using namespace std;

struct dl {
    int f, s, t;
    int typ;
    bool operator < (const dl& x) const {
        return t < x.t;
    }
};
struct dt{
    int val, L, R, lz;
};

int n, m, res;
dl a[maxn];
dt st[maxn << 2];
vector<int> val;

//void build(int id, int l, int r){
//    st[id].len = val[r] - val[l] + 1;
//    if (l == r) return;
//    int m = (l + r) >> 1;
//    build(id << 1, l, m);
//    build(id << 1 | 1, m + 1, r);
//}
void lazy(int id, int x){
    st[id].L += x;
    st[id].R += x;
    st[id].lz += x;
}
void down(int id){
    if (!st[id].lz) return;
    lazy(id << 1, st[id].lz);
    lazy(id << 1 | 1, st[id].lz);
    st[id].lz = 0;
}
void update(int id, int l, int r, int d, int c, int x){
    if (r < d || l > c) return;
    if (d <= l && r <= c){
        lazy(id, x);
        if ()
        return;
    }
    int m = (l + r) >> 1;
    down(id);
    update(id << 1, l, m, d, c, x);
    update(id << 1 | 1, m + 1, r, d, c, x);
    if (st[id].cnt == 0 && l < r){
        st[id].val = st[id << 1].val + st[id << 1 | 1].val;
    }
}
void update(int d, int c, int x){
    if (d <= c) update(1, 1, m, d, c, x);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    val.assign(n * 2 + 1, 0);
    fi(i, 1, n){
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        a[i] = {u + 1, x, v, 1};
        a[i + n] = {u + 1, x, y, -1};
        val[i - 1] = u + 1;
        val[i + n - 1] = x;
    }
    n <<= 1;
    sort(val.begin(), val.end());
    val.resize(unique(val.begin(), val.end()) - val.begin());
    m = val.size() - 1;
    fi(i, 1, n){
        a[i].f = lower_bound(val.begin(), val.end(), a[i].f) - val.begin();
        a[i].s = lower_bound(val.begin(), val.end(), a[i].s) - val.begin();
        cout << a[i].f << ' ' << a[i].s << '\n';
    }
    fi(i, 1, m) cout << val[i] << ' ';
    cout << endl;
    build(1, 1, m);
    fi(i, 1, 5) cout << st[i].len << ' ';
    cout << endl;
    fi(i, 1, n){
        //cout << st[1].val << ' ';
    fi(i, 1, 5) cout << st[i].val << ' ';
    cout << endl;
        if (a[i].t != a[i - 1].t)
            res += st[1].val * (a[i].t - a[i - 1].t);
        update(a[i].f, a[i].s, a[i].typ);
    }
    cout << res;
}
