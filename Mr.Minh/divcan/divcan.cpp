#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "divcan"
const int maxn = 1e5 + 5;
using namespace std;

const int mxn = 1e5 + 5;
const ll mod = 1e5 + 3;
ll fac[mxn], ifac[mxn], ans[mxn], a[mxn], n, m;

ll binpow(ll a, ll b){
    ll res = 1;
    while(b){
        if (b & 1) (res *= a) %= mod;
        b >>= 1;
        (a *= a) %= mod;
    }
    return res;
}

ll CC (ll n, ll k){
    if (n < k) return 0;
    return (fac[n] * ifac[n - k] % mod)* ifac[k] % mod;
}

ll C(ll n, ll k){
    ll res = 1;
    while(n){
        (res *= CC(n % mod, k % mod)) %= mod;
        n /= mod;
        k /= mod;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, n) cin >> a[i];

    fac[0] = 1;
    fi(i, 1, mod - 1) fac[i] = fac[i - 1] * i % mod;

    ifac[mod - 1] = binpow(fac[mod - 1], mod - 2);
    fid(i, mod - 2, 0) ifac[i] = ifac[i + 1] * (i + 1) % mod;

    int u = (1 << n) - 1;
    fi(x, 1, u){
        ll cnt = 0;
        fi(j, 0, n) if (x >> j & 1)
            cnt += a[j + 1] + 1;

        if (cnt > m) continue;
        ans[x] = C(m - cnt + n - 1, n - 1);
    }

    ll res = C(m + n - 1, n - 1);

    fi(x, 1, u){
        if (__builtin_popcount(x) & 1) res -= ans[x];
        else res += ans[x];
        if (res < 0) res += mod;
        res %= mod;
    }
    cout << res;
}
