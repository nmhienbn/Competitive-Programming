#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "collect"
const int maxn = 70;
using namespace std;

ll n, a[maxn];
int k, m;

ll calc(ll n){
    ll ans = 0;
    m = 0;
    while (n > 0){
        a[++m] = n / k;
        n /= k;
    }
    fi(i, 1, m - 1) a[i] -= a[i + 1];
    fi(i, 1, m) if (i & 1){
        ans += a[i];
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> k;
    ll d = 1, c = 1e18;
    while (d <= c){
        ll g = (d + c) >> 1;
        if (calc(g) >= n) c = g - 1;
        else d = g + 1;
    }
    cout << d;
}
