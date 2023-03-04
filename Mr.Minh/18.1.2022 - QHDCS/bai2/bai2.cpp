#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "bai2"
const int maxn = 20, maxk = 1e6 + 5;
using namespace std;

int n, k, a[maxn];
ll f[maxn][2][maxk][2];
string s;

ll calc(int len, bool flag, int product, bool nz){ //not zero :)
    if (len > n) return product == 0;
    ll& dem = f[len][flag][product][nz];
    if (~dem) return dem;
    dem = 0;
    int ub = flag ? a[len] : 9;
    fi(i, 0, ub){
        bool now = nz || i;
        int nex = product;
        if (now) nex = nex * i % k;
        if (flag && i == a[len])
            dem += calc(len + 1, 1, nex, now);
        else
            dem += calc(len + 1, 0, nex, now);
    }
    return dem;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> s >> k;
    k = abs(k);
    n = s.size();
    fi(i, 1, n) a[i] = s[i - 1] - '0';
    fi(i, 1, n) fi(j, 0, 1) fi(x, 0, k) fi(t, 0, 1)
        f[i][j][x][t] = -1;
    cout << calc(1, 1, 1, 0);

}
