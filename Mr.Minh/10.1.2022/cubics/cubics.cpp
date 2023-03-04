#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<long long,int>
#define pb push_back
#define ll long long
#define Irelia "cubics"
const int maxn = 1e5 + 5;
using namespace std;

int n, k, res, pos, now;
pii a[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> k;
    fi(i, 1, n){
        cin >> a[i].first;
        a[i].second = i;
        a[i].first += a[i - 1].first - k;
    }
    sort(a, a + n + 1);
    fi(i, 0, n){
        if (i == 0 || a[i].first != a[i - 1].first)
            now = a[i].second;
        if (a[i].second - now > res){
            res = a[i].second - now;
            pos = now;
        }
        else if (a[i].second - now == res){
            pos = min(pos, now);
        }
    }
    cout << res;
    if (res > 0) cout << ' ' << pos + 1;
}
