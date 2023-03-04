#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "price"
const int maxn = 5e5 + 5;
const ll INF = 1e18;
using namespace std;

int n, k;
ll f[maxn][2], g[maxn][2], s[maxn], res = INF, a[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> k;
    fi(i, 1, n) cin >> a[i];
    fid(i, n, 1) s[i] = s[i + 1] + a[i];
    fi(i, 1, n + 1) fi(j, 0, k) f[i][j] = INF;
    fi(i, 1, n + 1) fi(j, 0, k) g[i][j] = -INF;
    fid(i, n, 1){
        f[i][0] = min(f[i + 1][0], s[i]);
        g[i][0] = max(g[i + 1][0], s[i]);
    }
    res = min(res, f[1][0]);
    fi(j, 1, k){
        int now = j & 1;
        int pre = now ^ 1;
        fid(i, n - j, 1){
            f[i][now] = min(a[i] + f[i + 1][now], a[i] - g[i + 1][pre]);
            g[i][now] = max(a[i] + g[i + 1][now], a[i] - f[i + 1][pre]);
        }
        res = min(res, f[1][now]);
    }
    cout << res;
}
