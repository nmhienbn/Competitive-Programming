#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "bai3"
const int maxn = 20;
using namespace std;

int n, a[maxn];
string s;
ll f[maxn][2][10][2];

ll calc(int len, bool flag, int en, bool odd){
    if (len > n) return odd;
    ll& dem = f[len][flag][en][odd];
    if (~dem) return dem;
    dem = 0;
    int ub = flag ? a[len] : 9;
    fi(i, en, ub){
        if (flag && i == a[len])
            dem += calc(len + 1, 1, i, (i + odd) & 1);
        else
            dem += calc(len + 1, 0, i, (i + odd) & 1);
    }
    return dem;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> s;
    n = s.size();
    fi(i, 1, n) a[i] = s[i - 1] - '0';
    fi(i, 1, n) fi(j, 0, 1) fi(u, 0, 9) fi(v, 0, 1)
        f[i][j][u][v] = -1;
    cout << calc(1, 1, 0, 0);

}
