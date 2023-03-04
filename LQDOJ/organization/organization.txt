
#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "organization"
const int maxn = 1e5 + 5;
using namespace std;

int n, k, q;
int a[maxn];
ll sum;
int st[maxn << 2], lz[maxn << 2];

void build(int id, int l, int r){
    if (l == r){
        st[id] = a[l];
        return;
    }
    int m = (l + r) >> 1;
    build(id << 1, l, m);
    build(id << 1 | 1, m + 1, r);
    st[id] = max(st[id << 1], st[id << 1 | 1]);
}
void lazy(int id, int x){
    st[id] += x;
    lz[id] += x;
}
void down(int id){
    lazy(id << 1, lz[id]);
    lazy(id << 1 | 1, lz[id]);
    lz[id] = 0;
}
void update(int id, int l, int r, int d, int c){
    if (r < d || l > c || d > c) return;
    if (d <= l && r <= c){
        lazy(id, -1);
        return;
    }
    if (lz[id]) down(id);
    int m = (l + r) >> 1;
    update(id << 1, l, m, d, c);
    update(id << 1 | 1, m + 1, r, d, c);
    st[id] = max(st[id << 1], st[id << 1 | 1]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> k >> q;
    fi(i, 1, n) cin >> a[i], sum += a[i];
    build(1, 1, n);
    cout << max(sum / k + (sum % k > 0), 1ll * st[1]) << '\n';
    fi(i, 1, q){
        int l, r;
        cin >> l >> r;
        sum -= r - l + 1;
        update(1, 1, n, l, r);
        cout << i + max(sum / k + (sum % k > 0), 1ll * st[1]) << '\n';
    }
}
