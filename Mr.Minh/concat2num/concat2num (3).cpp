#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "concat2num"
const int maxn = 1e5+5;
using namespace std;

int t, n, a[maxn], b[maxn];
ll mu[20], l, r;

ll calc(ll C){
    ll ans = 0;
    int j = n;
    fi(i, 1, n){
        while (mu[b[j]] * a[i] + a[j] > C && j > 0) j--;
        ans += j;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
//    freopen(Irelia".inp", "r", stdin);
//    freopen(Irelia".out", "w", stdout);
    mu[0] = 1;
    fi(i, 1, 16) mu[i] = mu[i - 1] * 10;
    cin >> t;
    while (t--){
        cin >> n >> l >> r;
        fi(i, 1, n){
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        fi(i, 1, n){
            b[i] = upper_bound(mu + 1, mu + 17, a[i]) - mu;
        }
        cout << calc(r) - calc(l - 1) << '\n';
    }
}
