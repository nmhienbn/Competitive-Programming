#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "stock"
const int maxn = 1e5 + 5;

using namespace std;

int a[maxn], n, k;
int res, vt, pre[maxn], kq[maxn];
pii b[maxn * 4];
vector<int> co;

pii combine(pii a, pii b){
    if (a.first > b.first) return a;
    return b;
}

void update(int id, int l, int r, int vt, int val, int pos){
    if (l == r){
        b[id] = {val, pos};
        return;
    }
    int g = (l + r) >> 1;
    if (vt <= g) update(id*2, l, g, vt, val, pos);
    else update(id*2 + 1, g + 1, r, vt, val, pos);
    b[id] = combine(b[id*2], b[id*2 + 1]);
}

pii get(int id, int l, int r, int d, int c){
    if (c < d || r < d || l > c) return {0, 0};
    if (d <= l && r <= c) return b[id];
    int g = (l + r) >> 1;
    return combine(get(id*2, l, g, d, c), get(id*2 + 1, g + 1, r, d, c));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> k;
    k--;
    fi(i, 1, n){
        cin >> a[i];
        co.pb(a[i]);
    }
    sort(co.begin(), co.end());
    co.resize(unique(co.begin(), co.end()) - co.begin());
    fi(i, 1, n){
        int now  = lower_bound(co.begin(), co.end(), a[i])   - co.begin() + 1;
        int dau  = lower_bound(co.begin(), co.end(), a[i]-k) - co.begin();
        int cuoi = upper_bound(co.begin(), co.end(), a[i]+k) - co.begin() + 1;
        pii ans = combine(get(1, 1, n, 1, dau), get(1, 1, n, cuoi, n));
        update(1, 1, n, now, ans.first + 1, i);
        if (res < ans.first + 1){
            res = ans.first + 1;
            vt = i;
        }
        pre[i] = ans.second;
    }
    fid(i, res, 1){
        kq[i] = vt;
        vt = pre[vt];
    }
    cout << res << '\n';
    fi(i, 1, res) cout << a[kq[i]] << ' ';
}
