#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "balloons"
const int maxn = 2e5 + 5;
using namespace std;

int n, m, a[maxn], b[maxn];
int st[maxn << 2], T[maxn << 4], pos[maxn << 4];

void build(int id, int l, int r){
    if (l == r){
        st[id] = a[l];
        pos[id] = l;
        return;
    }
    int mid = (l + r) >> 1;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = max(st[id * 2], st[id * 2 + 1]);
}

void lazy(int id){
    if (T[id] == 0) return;
    fi(j, id * 2, id * 2 + 1){
        st[j] += T[id];
        T[j] += T[id];
    }
    T[id] = 0;
}

void update(int id, int l, int r, int d, int c, int x){
    if (r < d || l > c || d > c) return;
    if (d <= l && r <= c){
        st[id] += x;
        T[id] += x;
        return;
    }
    int mid = (l + r) >> 1;
    lazy(id);
    update(id * 2, l, mid, d, c, x);
    update(id * 2 + 1, mid + 1, r, d, c, x);
    st[id] = max(st[id * 2], st[id * 2 + 1]);
}

int get(int id, int l, int r, int vt){
    if (vt < l || vt > r) return 0;
    if (l == r) return st[id];
    int mid = (l + r) >> 1;
    lazy(id);
    if (vt <= mid) return get(id * 2, l, mid, vt);
    return get(id * 2 + 1, mid + 1, r, vt);
}

int getVT(int id, int l, int r, int gt){
    if (gt > st[id]) return n + 1;
    if (l == r) return pos[id];
    int mid = (l + r) >> 1;
    lazy(id);
    if (st[id * 2] >= gt) return getVT(id * 2, l, mid, gt);
    return getVT(id * 2 + 1, mid + 1, r, gt);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, n) cin >> a[i];
    fi(i, 1, m) cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1, greater<int>());
    build(1, 1, n);
    fi(i, 1, m){
        int bd = get(1, 1, n, n - b[i] + 1);
        if (bd <= 0){
            cout << "NO";
            exit(0);
        }
        int vt1 = getVT(1, 1, n, bd), vt2 = getVT(1, 1, n, bd + 1);
        update(1, 1, n, vt2, n, -1);
        update(1, 1, n, vt1, vt1 + b[i] - (n - vt2 + 1) - 1, -1);
    }
    cout << "YES";
}
