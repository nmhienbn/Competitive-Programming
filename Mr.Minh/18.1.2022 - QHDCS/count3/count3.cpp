#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "count3"
const int maxn = 20;
using namespace std;

int n, a[maxn], m, b[maxn];
ll A, B, N, res;
ll f[maxn][2][2];

void toS(int& n, int a[], ll N){
    n = 0;
    do {
        a[++n] = N % 10;
        N /= 10;
    }
    while (N > 0);
    reverse(a + 1, a + n + 1);
}

ll calc(int len, bool flag, int l, int r, bool nz){
    if (len > n) return nz;
    ll& dem = f[len][flag][nz];
    if (~dem) return dem;
    dem = 0;
    int lb = 0;
    int ub = flag ? a[len] : 9;
    if (l <= len && len <= r){
        int i = b[len - l + 1];
        if (i <= ub && (nz || i)){
            dem += calc(len + 1, flag && (i == a[len]), l, r, 1);
        }
    }
    else {
        fi(i, lb, ub){
            dem += calc(len + 1, flag && (i == a[len]), l, r, nz || i);
        }
    }
    return dem;
}

ll solve(ll A){
    if (A < 0) return 0;
    ll ans = 0;
    toS(n, a, A);
    fi(i, 1, n - m + 1){
        memset(f, -1, sizeof f);
        ans += calc(1, 1, i, i + m - 1, 0);
    }
    if (N == 0) ans++;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    while (cin >> A >> B >> N){
        if (A == -1) break;
        toS(m, b, N);
        //cout << solve(B) << ' ' << solve(A - 1) << ' ';
        cout << solve(B) - solve(A - 1) << '\n';
    }
}
