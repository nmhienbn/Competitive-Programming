#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "cone"
const int maxn = 1e5 + 5;
using namespace std;

int n, a[maxn], val[maxn], id;
pii b[maxn];
ll bit[maxn], f[maxn], g[maxn], res;

int calc(int x){
    int ans = 0;
    while (x > 0){
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

void nhapA(){
    fi(i, 1, n) cin >> b[i].first, b[i].second = i;
    sort(b + 1, b + n + 1);
    fi(i, 1, n){
        if (b[i].first != b[i - 1].first) val[++id] = calc(b[i].first);
        a[b[i].second] = id;
    }
}

void update(int x, ll val){
    while (x <= n){
        bit[x] = max(bit[x], val);
        x += x & -x;
    }
}

ll get(int x){
    ll ans = 0;
    while (x > 0){
        ans = max(ans, bit[x]);
        x -= x & -x;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    nhapA();
    fi(i, 1, n){
        f[i] = get(a[i] - 1) + val[a[i]];
        update(a[i], f[i]);
    }
    fi(i, 0, n) bit[i] = 0;
    fid(i, n, 1){
        g[i] = get(a[i] - 1) + val[a[i]];
        update(a[i], g[i]);
    }
    fi(i, 1, n){
        res = max(res, f[i] + g[i] - val[a[i]]);
    }
    cout << res;
}
