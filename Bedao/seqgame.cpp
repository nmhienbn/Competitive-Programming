#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "seqgame"
const int maxn = 1e5 + 6;
using namespace std;

struct dl {
    int l, r, d;
} b[maxn];

int n, m;
ll a[maxn];
ll f[maxn], g[maxn], res = 1e18;

void minimize(ll& x, ll y){
    if (x > y) x = y;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    for (int i = 1, l, r, d; i <= m; i++){
        cin >> l >> r >> d;
        a[l] += d;
        a[r + 1] -= d;
        b[i] = {l, r, d};
    }
    fi(i, 1, n) a[i] += a[i - 1];
    fi(i, 1, n)  f[i] = max(f[i - 1], a[i]);
    fid(i, n, 1) g[i] = max(g[i + 1], a[i]);
    for (int i = 1, l, r, d; i <= m; i++){
        l = b[i].l, r = b[i].r, d = b[i].d;
        minimize(res, max(f[l - 1], max(f[r] - d, g[r + 1])));
    }
    cout << res;
}
