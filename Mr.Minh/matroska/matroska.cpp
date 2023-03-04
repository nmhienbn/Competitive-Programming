#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "matroska"
const int maxn = 1e5+5;
using namespace std;

int n, a[maxn], cnt1[maxn], cnt2[maxn],
    maxa, st[maxn << 2], T[maxn << 2], gt[maxn];
pii b[maxn];

void build(int id, int l, int r){
    if(l == r){
        st[id] = gt[l];
        return;
    }
    int m = (l+r) >> 1;
    build(id*2, l, m);
    build(id*2+1, m+1, r);
    st[id] = min(st[id*2], st[id*2+1]);
}

void lazy(int id){
    fi(i, id*2, id*2+1){
        T[i] += T[id];
        st[i] += T[id];
    }
    T[id] = 0;
}

void update(int id, int l, int r, int d, int c, int val){
    if(r < d || c < l) return;
    if(d <= l && r <= c){
        st[id] += val;
        T[id] += val;
        return;
    }
    lazy(id);
    int m = (l+r) >> 1;
    update(id*2, l, m, d, c, val);
    update(id*2+1, m+1, r, d, c, val);
    st[id] = min(st[id*2], st[id*2+1]);
}

void nhap(){
    cin >> n;
    fi(i, 1, n) cin >> b[i].first, b[i].second = i;
    sort(b+1, b+n+1);
    a[b[1].second] = 1;
    int id = 1;
    fi(i, 2, n){
        if (b[i].first > b[i-1].first) id++;
        a[b[i].second] = id;
    }
    maxa = *max_element(a+1, a+n+1);
}

void solve(){
    int t = n >> 1;
    fi(i, 1, t) cnt1[a[i]]++;
    fi(i, t+1, t*2) cnt2[a[i]]++;
    fid(i, maxa, 1) gt[i] = gt[i+1] + cnt2[i+1] - cnt1[i];
    build(1, 1, maxa);
    fid(i, t, 1){
        if (st[1] >= 0){
            cout << i;
            exit(0);
        }
        update(1, 1, maxa, 1, a[i*2] - 1, -1);
        update(1, 1, maxa, 1, a[i*2-1] - 1, -1);
        update(1, 1, maxa, 1, a[i] - 1, 1);
        update(1, 1, maxa, 1, a[i], 1);
    }
    cout << 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    nhap();
    solve();
}
