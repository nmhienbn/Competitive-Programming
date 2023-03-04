#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define mul(x, y) x = 1ll * x * y % mod
#define pb push_back
#define ll long long
#define Irelia "itstr"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

const int maxn = 1e5 + 5, mod = 1007050321, inv = mod / 2 + 1;

int n, q, st[maxn << 2], T[maxn << 2], mu[maxn], imu[maxn], now;
string s;
ordered_set ss;

//int bit[maxn];
//void update(int x, int val){
//    while (x <= n){
//        bit[x] += val;
//        x += x & -x;
//    }
//}
//
//int get(int x){
//    int k = 0;
//    fid(i, 16, 0){
//        if (bit[k + (1 << i)] <= x) k += (1 << i);
//        x -= bit[k];
//    }
//    return k;
//}

int cong(int x, int y){
    x += y;
    if (x >= mod) return x - mod;
    return x;
}

void build(int id, int l, int r){
    T[id] = 1;
    if (l == r){
        st[id] = (s[l - 1] - '0') * mu[n - l];
        return;
    }
    int m = (l + r) >> 1;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
    st[id] = cong(st[id * 2], st[id * 2 + 1]);
}

void lazy(int id){
    fi(j, id * 2, id * 2 + 1){
        mul(st[j], T[id]);
        mul(T[j], T[id]);
    }
    T[id] = 1;
}

void update(int id, int l, int r, int vt){
    if (l == r){
        st[id] = 0;
        return;
    }
    int m = (l + r) >> 1;
    lazy(id);
    if (vt <= m) update(id * 2, l, m, vt);
    else update(id * 2 + 1, m + 1, r, vt);
    st[id] = cong(st[id * 2], st[id * 2 + 1]);
}

void update(int id, int l, int r, int d, int c, int val){
    if (r < d || l > c || d > c) return;
    if (d <= l && r <= c){
        mul(st[id], val);
        mul(T[id], val);
        return;
    }
    int m = (l + r) >> 1;
    lazy(id);
    update(id * 2, l, m, d, c, val);
    update(id * 2 + 1, m + 1, r, d, c, val);
    st[id] = cong(st[id * 2], st[id * 2 + 1]);
}

int get(int id, int l, int r, int d, int c){
    if (r < d || l > c || d > c) return 0;
    if (d <= l && r <= c) return st[id];
    int m = (l + r) >> 1;
    lazy(id);
    return cong(get(id * 2, l, m, d, c),
                get(id * 2 + 1, m + 1, r, d, c));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> s >> q;
    now = n = s.size();
    mu[0] = imu[0] = 1;
    fi(i, 1, n){
        mu[i] = mu[i - 1] * 2 % mod;
        imu[i] = 1ll * imu[i - 1] * inv % mod;
    }
    build(1, 1, n);
    fi(i, 0, n) ss.insert(i);
    while (q--){
        char typ;
        int l, r;
        cin >> typ >> l;
        l = *ss.find_by_order(l);
        if (typ == '?'){
            cin >> r;
            int nr = *ss.find_by_order(r);
            //cout << l << ' ' << nr << ' ';
            cout << 1ll * get(1, 1, n, l, nr) * imu[now - r] % mod << '\n';
        }
        else {
            now--;
            ss.erase(l);
            update(1, 1, n, l);
            update(1, 1, n, 1, l, inv);
        }
    }
}
