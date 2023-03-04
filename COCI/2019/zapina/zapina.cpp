#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "zapina"
const int maxn = 355, mod = 1e9 + 7;
using namespace std;

int mu(int a, int k){
    ll ans = 1;
    ll lt = a;
    while (k > 0){
        if (k & 1) ans = ans * lt % mod;
        lt = lt * lt % mod;
        k >>= 1;
    }
    return ans;
}

int n, fact[maxn], ifact[maxn];
int res;

void add(int& x, int y){
    x += y;
    if (x >= mod) x -= mod;
}

void sub(int& x, int y){
    x -= y;
    if (x < 0) x += mod;
}

int C(int n, int k){
    return (1ll * fact[n] * ifact[k] % mod) * ifact[n - k] % mod;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    if (n == 1){
        cout << 1;
        exit(0);
    }
    fact[0] = 1;
    fi(i, 1, n) fact[i] = 1ll * fact[i - 1] * i % mod;
    ifact[n] = mu(fact[n], mod - 2);
    fid(i, n, 1) ifact[i - 1] = 1ll * ifact[i] * i % mod;
    fi(i, 1, n){
        if (i & 1) add(res, 1ll * C(n, i) * C(n * 2 - i - 2, n - 2) % mod);
        else sub(res, 1ll * C(n, i) * C(n * 2 - i - 2, n - 2) % mod);
    }
    cout << res;
}
