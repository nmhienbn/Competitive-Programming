#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "reflective"
const int maxn = 0;
using namespace std;

ll l, r;

ll calc(ll x){
    ll ans = 0;
    while (x > 0){
        x >>= 1;
        ans += x;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
//    freopen(Irelia".inp", "r", stdin);
//    freopen(Irelia".out", "w", stdout);
    cin >> l >> r;
    cout << calc(r) - calc(l - 1);
}
