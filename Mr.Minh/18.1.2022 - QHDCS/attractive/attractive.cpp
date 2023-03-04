#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "attractive"
const int maxn = 110;
using namespace std;

ll f[14][2][maxn][maxn];
string a;
int n;
ll res;

ll calc(int len, bool flag, int rem, int u, int sum){
    if (len > n) return rem == 0 && sum == u;
    if (~f[len][flag][rem][sum]) return f[len][flag][rem][sum];
    ll& dem = f[len][flag][rem][sum];
    dem = 0;
    int ub = flag ? a[len] - '0' : 9;
    fi(i, 0, ub) if (sum + i <= u){
        if (flag && a[len] == '0' + i)
            dem += calc(len + 1, 1, (rem * 10 + i) % u, u, sum + i);
        else
            dem += calc(len + 1, 0, (rem * 10 + i) % u, u, sum + i);
    }
    else break;
    return dem;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> a;
    n = a.size();
    a = ' ' + a;
    fi(i, 1, min(n, 12) * 9){
        memset(f, -1, sizeof f);
        res += calc(1, 1, 0, i, 0);
    }
    cout << res;
}
