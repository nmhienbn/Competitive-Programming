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
	string X = "", Y = "", Z;
	for (; x > 0; x /= 10) X = X + char(x%10+'0');
	for (; y > 0; y /= 10) Y = Y + char(y%10+'0');
	Z.resize(X.size() + Y.size(), '0');
	for (int i = 0; i < X.size(); i++){
		int c = 0;
		for (int j = 0; j < Y.size(); j++){
			c += (Z[i+j]-'0') + (X[i]-'0')*(Y[j]-'0');
			Z[i+j] = char(c%10+'0');
			c /= 10;
		}
		if (c > 0) Z[i+Y.size()] += c;
	}
	ll ans = 0;
	fid(i, Z.size()-1, 0) ans = (ans*10 + Z[i]-'0') % mod;
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
        if (m <= 1e9){
                fi(i, 1, n){
                res = (res*(h[d]%m) + x) % m;
            }
        }
        else {
            fi(i, 1, n){
                res = (mul(res, h[d], m) + x) % m;
            }
        }
        cout << res << '\n';
    }
}
