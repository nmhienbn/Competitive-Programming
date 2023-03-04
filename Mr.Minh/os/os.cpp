#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "os"
const int maxn = 2e5+5;

using namespace std;

int n, m, res, st[maxn*4], T[maxn*4];
pii a[maxn];
vector<int> b;

void lazy(int id){
    st[id * 2] = st[id * 2 + 1] = T[id * 2] = T[id * 2 + 1] = 1;
    T[id] = 0;
}

void update(int id, int l, int r, int d, int c){
    if (r < d || l > c) return;
    if (d <= l && r <= c){
        st[id] = 1;
        T[id] = 1;
        return;
    }
    int m = (l + r) >> 1;
    if (T[id] > 0) lazy(id);
    update(id * 2, l, m, d, c);
    update(id * 2 + 1, m + 1, r, d, c);
    st[id] = max(st[id * 2], st[id * 2 + 1]);
}

int get(int id, int l, int r, int d, int c){
    if (r < d || l > c) return 0;
    if (d <= l && r <= c) return st[id];
    int m = (l + r) >> 1;
    if (T[id] > 0) lazy(id);
    return max(get(id * 2, l, m, d, c),
               get(id * 2 + 1, m + 1, r, d, c));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> m >> n;
    fi(i, 1, n){
        int u, v;
        cin >> u >> v;
        a[i] = {u, v};
        b.pb(u);
        b.pb(v);
    }
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    int m = b.size();
    fid(i, n, 1){
        a[i].first  = lower_bound(b.begin(), b.end(), a[i].first)  - b.begin() + 1;
        a[i].second = lower_bound(b.begin(), b.end(), a[i].second) - b.begin() + 1;
        if (get(1, 1, m, a[i].first, a[i].second) == 0) res++;
        update (1, 1, m, a[i].first, a[i].second);
    }
    cout << res;
}
