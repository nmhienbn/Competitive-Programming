#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "flower"
const int maxn = 55, mod = 1e9 + 7;
using namespace std;

int binpow(int a, int k){
    if (k == 0) return 1;
    int tg = binpow(a, k >> 1);
    if (k & 1) return (1ll * tg * tg % mod) * a % mod;
    return 1ll * tg * tg % mod;
}

int n, m, k, f[5];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> m >> n >> k;
    f[1] = 4;
    f[2] = 6ll * (binpow(2, n) - 2 + mod) % mod;
    f[3] = (4ll * binpow(3, n) - 12ll * binpow(2, n) + 12 + 12ll * mod) % mod;
    f[4] = (binpow(4, n) - f[3] - f[2] - f[1] + 3ll * mod) % mod;

    fid(i, 3, 1) f[i] += f[i + 1], f[i] %= mod;
    cout << binpow(f[k], m);
}
