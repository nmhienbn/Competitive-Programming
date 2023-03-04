#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "bint1"
const int maxn = 2005, mod = 1e9 + 7;
using namespace std;

int nt, n;
int fact[maxn], ifact[maxn];

int binpow(int a, int k){
    int lt = a;
    int res = 1;
    while (k > 0){
        if (k & 1) res = 1ll * res * lt % mod;
        lt = 1ll * lt * lt % mod;
        k >>= 1;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    fact[0] = 1;
    fi(i, 1, 2000) fact[i] = 1ll * fact[i - 1] * i % mod;
    ifact[2000] = binpow(fact[2000], mod - 2);
    fid(i, 2000, 1) ifact[i - 1] = 1ll * ifact[i] * i % mod;
    cin >> nt;
    while (nt--){
        cin >> n;
        cout << (1ll * fact[n * 2] * ifact[n + 1] % mod) * ifact[n] % mod << '\n';
    }
}
