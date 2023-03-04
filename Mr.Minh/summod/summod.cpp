#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "summod"
const int mod = 1000000007;
using namespace std;
ll n, res, k, l, r, L;

void cal(ll m){
    if (m <= 0) return;
    k = n / m;
    r = n % m % mod;
    l = n / (k + 1) + 1;
    L = (m - l + 1) % mod;
    res = (res + L * r + k % mod * (L * (L-1) / 2 % mod)) % mod;
    if (l - 1) cal(l - 1);
}

ll a, b;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    //freopen(Irelia".inp", "r", stdin);
    //freopen(Irelia".out", "w", stdout);
    cin >> a >> b >> n;
    cal(a - 1);
    res = mod - res;
    cal(b);
    cout << res;
}
