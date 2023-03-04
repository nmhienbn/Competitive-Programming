#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "birthday"
const int maxn = 1e3+5, mod = 1e9+7;

using namespace std;

int muy[maxn];

long long fact[(int)1e5+5];

ll binpow(ll a, ll n) {
    long long res = 1;
    while (n > 0) {
        if (n % 2 != 0) {
            res = (res * a) % mod;
        }
        a = ((long long)a * a) % mod;
        n /= 2;
    }
    return (ll)res;
}

ll C(ll N, ll K) {
    if (K > N) {
        return 0;
    }
    return (((fact[N] * binpow(fact[N - K], mod - 2)) % mod) * binpow(fact[K], mod - 2)) % mod;
}

void sang(){
    muy[1] = 1;
    for (int i = 1; i <= 1e3; i++)
      for (int j = 2*i; j <= 1e3; j += i)
          muy[j] -= muy[i];
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    sang();
    fact[0] = 1;
    fi(i, 1, 1e5){
        fact[i] = (fact[i - 1] * i) % mod;
    }
    int q;
    cin >> q;
    while (q--){
        ll res = 0;
        int n, m;
        cin >> m >> n;
        if (m > 1e3){
            cout << C(m-1, n-1) << '\n';
            continue;
        }
        fi(i, n, m){
            if (m % i == 0 && muy[m/i] != 0){
                res += C(i-1, n-1)*muy[m/i] + mod;
                res %= mod;
            }
        }
        cout << res << '\n';
    }
}
