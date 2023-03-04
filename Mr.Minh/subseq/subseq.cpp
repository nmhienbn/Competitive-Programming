#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "subseq"
const int maxn = 1e5+5;
using namespace std;

int n, del, a[maxn], res, idres, luu[maxn], kq[maxn];
pii st[maxn << 2];
vector<int> b;

pii merge(pii a, pii b){
    if (a.first >= b.first) return a;
    return b;
}

void update(int id, int l, int r, int vt, int val, int pos){
    if (l == r){
        if (st[id].first < val){
            st[id] = {val, pos};
        }
        return;
    }
    int m = (l + r) >> 1;
    if (vt <= m) update(id*2, l, m, vt, val, pos);
    else update(id*2+1, m+1, r, vt, val, pos);
    st[id] = merge(st[id*2], st[id*2+1]);
}

pii get(int id, int l, int r, int d, int c){
    if (c < d || r < d || l > c) return {0, 0};
    if (d <= l && r <= c) return st[id];
    int m = (l + r) >> 1;
    return merge(get(id*2, l, m, d, c), get(id*2+1, m+1, r, d, c));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> del;
    fi(i, 1, n) cin >> a[i], b.pb(a[i]);
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    fi(i, 1, n){
        int now = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
        int pre = lower_bound(b.begin(), b.end(), a[i] - del) - b.begin() + 1;
        int nex = lower_bound(b.begin(), b.end(), a[i] + del + 1) - b.begin();

        pii gt = get(1, 1, n, pre, nex);
        int len = gt.first + 1;
        luu[i] = gt.second;
        if (len > res){
            res = len;
            idres = i;
        }
        update(1, 1, n, now, len, i);
    }
    cout << res << '\n';
    fid(i, res, 1){
        kq[i] = a[idres];
        idres = luu[idres];
    }
    fi(i, 1, res){
        cout << kq[i] << ' ';
    }
}
