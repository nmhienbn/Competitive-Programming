#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "candy"
const int maxn = 2e5 + 5;

using namespace std;

int n, a[maxn];
ll sum, now, res = 1e18;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    //freopen(Irelia".inp", "r", stdin);
    //freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i], sum += a[i];
    fi(i, 1, n){
        now += a[i];
        res = min(res, abs(sum - now * 2));
    }
    cout << res;
}
