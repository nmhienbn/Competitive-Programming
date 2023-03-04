#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "addition"
const int maxn = 20;
using namespace std;

ll a, b, c, mu[maxn];
set<ll> res;

ll cong(ll a, ll b){
    int cnt = 0, now;
    ll ans = 0;
    while (a > 0 || b > 0){
        now = a % 10 + b % 10;
        ans += now * mu[cnt];
        cnt += 1 + (now > 9);
        a /= 10;
        b /= 10;
    }
    return ans;
}

ll calc(ll a, ll b, ll c){
    return cong(cong(a, b), c);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    mu[0] = 1;
    fi(i, 1, 18) mu[i] = mu[i - 1] * 10;
    cin >> a >> b >> c;
    res.insert(calc(a, b, c));
    res.insert(calc(b, c, a));
    res.insert(calc(c, a, b));
    if (res.size() == 1) cout << "NO\n";
    else cout << "YES\n";
    for (ll it : res) cout << it << '\n';
}
