#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "necklace"
const int maxn = 1e5+5, mod = 1e9+7;
using namespace std;

int n, k, a[maxn], phi[maxn], mu[maxn], nt;
ll res;

ll binpow(ll a, int k){
    if (k == 1) return a;
    ll tg = binpow(a, k >> 1);
    tg = (tg*tg) % mod;
    if (k&1) return tg*a % mod;
    return tg;
}

void Erathosenes(){
    fi(i, 1, 1e5) a[i] = i;
    fi(i, 2, 320) if (a[i] == i){
        for (int j = i*i; j <= 1e5; j += i){
            a[j] = i;
        }
    }
    phi[1] = 1;
    fi(i, 2, 1e5){
        int p = a[i], cnt = 1, u = i/p;
        while (u % p == 0){
            cnt *= p;
            u /= p;
        }
        phi[i] = phi[u]*cnt*(p-1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    Erathosenes();
    cin >> nt;
    mu[0] = 1;
    while (nt--){
        res = 0;
        cin >> n >> k;
        fi(i, 1, n) mu[i] = (1ll*mu[i-1] * k) % mod;
        for (int i = 1; i*i <= n; i++) if (n % i == 0){
            res = (res + 1ll*phi[i]*mu[n/i]) % mod;
            if (i != n/i) res = (res + 1ll*phi[n/i]*mu[i]) % mod;
        }
        cout << res*binpow(n, mod-2) % mod << '\n';
    }
}
