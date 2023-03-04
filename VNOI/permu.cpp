#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "permu"
const int maxn = 1e5 + 5, mod = 1e9 + 7;
using namespace std;

int n, m, k;
int a[maxn];
int fact[maxn], ifact[maxn];
int res;

ll binpow(ll a, int k){
    ll res = 1, now = a;
    while (k > 0){
        if (k & 1) res = res * now % mod;
        now = now * now % mod;
        k /= 2;
    }
    return res;
}

int f(int k, int x){
    return ((1LL * fact[k] * ifact[k - x] % mod) * ifact[x] % mod) * fact[n - x] % mod;
}

void add(int& x, int y){
    x += y;
    if (x >= mod) x -= mod;
}
void sub(int& x, int y){
    x -= y;
    if (x < 0) x += mod;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, m){
        int l, r;
        cin >> l >> r;
        a[l]++;
        a[r + 1]--;
    }
    fi(i, 1, n) a[i] += a[i - 1], k += a[i] > 0;
    fact[0] = ifact[0] = 1;
    fi(i, 1, n) fact[i] = 1LL * fact[i - 1] * i % mod;
    ifact[n] = binpow(fact[n], mod - 2);
    fid(i, n - 1, 1) ifact[i] = 1LL * ifact[i + 1] * (i + 1) % mod;
    fi(i, 0, k){
        if (i & 1) sub(res, f(k, i));
        else add(res, f(k, i));
    }
    cout << res;
}
