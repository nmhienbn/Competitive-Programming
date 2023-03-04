#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "demso"
const int maxn = 20;
using namespace std;

int n, a[maxn], d, k;
ll f[maxn][2][maxn][10][2];
ll A, B;

ll calc(int len, bool flag, int cnt, int en, int nz){
    if (cnt > k) return 0;
    if (len > n) return 1;
    ll& dem = f[len][flag][cnt][en][nz];
    if (~dem) return dem;
    dem = 0;
    int ub = flag ? a[len] : 9;
    fi(i, 0, ub){
        dem += calc(len + 1, flag && i == a[len], cnt + (abs(en - i) <= d && nz), i, nz || i);
    }
    return dem;
}

ll solve(ll A){
    n = 0;
    do {
        a[++n] = A % 10;
        A /= 10;
    }
    while (A > 0);
    reverse(a + 1, a + n + 1);
    //memset(f, -1, sizeof f);
    fi(i, 1, n) fi(j, 0, 1) fi(u, 0, k) fi(v, 0, 9) fi(t, 0, 1)
        f[i][j][u][v][t] = -1;
    return calc(1, 1, 0, 0, 0);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> A >> B >> d >> k;
    cout << solve(B) - solve(A - 1);
}
