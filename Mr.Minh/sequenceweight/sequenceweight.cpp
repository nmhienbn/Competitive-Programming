#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "sequenceweight"
const int maxn = 1e5 + 5;
using namespace std;

int t, n;
pii a[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> t;
    while (t--){
        cin >> n;
        fi(i, 1, n) cin >> a[i].first, a[i].second = i;
        sort(a + 1, a + n + 1);
        ll res = 0;
        ll cnt = 0;
        fi(i, 1, n){
            if (a[i].first != a[i - 1].first) cnt = a[i].second;
            else {
                res += cnt * (n - a[i].second + 1);
                cnt += a[i].second;
            }
        }
        cout << res << '\n';
    }

}
