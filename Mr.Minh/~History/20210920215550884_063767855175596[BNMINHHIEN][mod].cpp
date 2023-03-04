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

ll n, m, x, h[15];

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
        ll res = 0;
        ll d = 0, c = x;
        do {
            d++;
            c /= 10;
        }
        while (c > 0);
        ll t = h[d]%m;
        if (m <= 1e9){
                fi(i, 1, n){
                res = (res*t + x) % m;
            }
        }
        else {
            fi(i, 1, n){
                res = (mul(res, t, m) + x) % m;
            }
        }
        cout << res << '\n';
    }
}
