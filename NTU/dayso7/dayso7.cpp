#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "dayso7"
const int maxn = 2e5 + 5;
using namespace std;

int n, a[maxn];
ll f[maxn], g[maxn], pre[3], now, res = -1e18;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i];
    pre[1] = pre[2] = 1e18;
    fi(i, 1, n){
        int j = i % 3;
        now += a[i];
        f[i] = now - pre[j];
        if (i > 1) f[i] = max(f[i], f[i - 1]);
        pre[j] = min(pre[j], now);
    }
    pre[0] = pre[1] = pre[2] = 1e18;
    g[(n + 1) % 3] = pre[(n + 1) % 3] = 1e18;
    now = 0;
    fid(i, n, 1){
        int j = i % 3;
        now += a[i];
        g[i] = now - pre[j];
        if (i < n) g[i] = max(g[i], g[i + 1]);
        pre[j] = min(pre[j], now);
    }
    fi(i, 1, n - 1){
        res = max(res, f[i] + g[i + 1]);
    }
    cout << res;
}
