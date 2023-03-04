#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define getbit(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "segxor"
const int maxn = 1e5+5;
using namespace std;

int n, q, a[maxn], b[maxn], st[30][maxn * 4], T[maxn * 4], res[30];

void build(int id, int l, int r){
    if (l == r){
        fi(k, 0, 27) st[k][id] = getbit(a[l], k);
        return;
    }
    int m = (l + r) >> 1;
    build(id * 2, l, m);
    build(id * 2 + 1, m+1, r);
    fi(k, 0, 27) st[k][id] = st[k][id * 2] + st[k][id * 2 + 1];
}

void lazy(int id, int l, int m, int r){
    if (T[id] == 0) return;
    fi(k, 0, 27){
        if (getbit(T[id], k)){
            st[k][id * 2] = m - l + 1 - st[k][id * 2];
            st[k][id * 2 + 1] = r - m - st[k][id * 2 + 1];
        }
    }
    T[id * 2] ^= T[id];
    T[id * 2 + 1] ^= T[id];
    T[id] = 0;
}

void update(int id, int l, int r, int d, int c, int val){
    if (r < d || l > c) return;
    if (d <= l && r <= c){
        fi(k, 0, 27) if (getbit(val, k)){
            st[k][id] = r - l + 1 - st[k][id];
        }
        T[id] ^= val;
        return;
    }
    int m = (l + r) >> 1;
    lazy(id, l, m, r);
    update(id * 2, l, m, d, c, val);
    update(id * 2 + 1, m+1, r, d, c, val);
    fi(k, 0, 27) st[k][id] = st[k][id * 2] + st[k][id * 2+1];
}

void get(int id, int l, int r, int d, int c){
    if (r < d || l > c) return;
    if (d <= l && r <= c){
        fi(k, 0, 27) res[k] += st[k][id];
        return;
    }
    int m = (l + r) >> 1;
    lazy(id, l, m, r);
    get(id * 2, l, m, d, c);
    get(id * 2 + 1, m+1, r, d, c);
    fi(k, 0, 27) st[k][id] = st[k][id * 2] + st[k][id * 2 + 1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> q;
    fi(i, 1, n) cin >> b[i], a[i] = a[i-1] ^ b[i];
    build(1, 0, n);
    fi(i, 1, q){
        int typ, u, v;
        cin >> typ >> u >> v;
        if (typ == 1){
            update(1, 0, n, u, n, (b[u] ^ v));
            b[u] = v;
        }
        else {
            ll ans = 0;
            fi(j, 0, 27) res[j] = 0;
            get(1, 0, n, u - 1, v);
            fi(j, 0, 27){
                ans += (1ll << j) * res[j] * (v - u + 2 - res[j]);
            }
            cout << ans << '\n';
        }
    }
}
