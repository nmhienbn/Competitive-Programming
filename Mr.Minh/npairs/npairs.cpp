#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "npairs"
const int maxn = 0;
using namespace std;

ll a, b, c, d, s, u, v, res, e, f;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> a >> b >> c >> d;
    e = __gcd(a, c);
    f = __gcd(b, d);
    a /= e, c /= e;
    b /= f, d /= f;
    s = a*d - b*c;
    if (s < 0) s = -s;
    fi(x, 1, s-1){
        u = a*x, v = c*x;
        fi(y, 1, s-1){
            u += b;
            v += d;
            if (u % s == 0 && v % s == 0){
                res++;
            }
        }
    }
    cout << res*e*f;
}
