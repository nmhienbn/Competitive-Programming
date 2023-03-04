#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "mod"
const int maxn = 1e6+5;

using namespace std;

ll n, m, x, h[15], y, mu;

ll mul(ll x, ll y, ll mod) {
	if (x == 0 || y == 0) return 0;
	ll ans = 0;
	string X;
	while (x > 0){
        X = char(x%10 + '0') + X;
        x /= 10;
	}
	for (auto c : X){
        ans = (ans*10 + y*(c - '0')) % mod;
	}
	return ans;
}

ll bin(ll n, ll mod){
    if (n == 0){
        return 0;
    }
    ll tg = bin(n/2, mod);
    ll res = (mul(tg, y, mod) + tg) % mod;
    y = mul(y, y, mod);
    if (n&1){
        res = (res + mul(x, y, mod)) % mod;
        y = mul(mu, y, mod);
    }
    return res;
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    h[0] = 1;
    fi(i, 1, 13) h[i] = h[i-1] * 10;
    int t;
    cin >> t;
    while (t--){
        cin >> x >> n >> m;
        if (m == 3 || m == 9){
            cout << (x%m)*(n%m) % m << '\n';
            continue;
        }
        ll c = x;
        mu = y = 1;
        while (c){
            mu = mu * 10 % m;
            c /= 10;
        }
        cout << bin(n, m) << '\n';
    }
}
