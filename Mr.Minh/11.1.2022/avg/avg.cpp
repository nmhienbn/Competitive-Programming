#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "avg"
const int maxn = 1005;
using namespace std;

int x, y, n, m, res, nt;
pii a[maxn], b[maxn], c[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> nt;
    while (nt--){
        n = m = 0;
        res = 0;
        cin >> x;
        fi(i, 1, x){
            cin >> y;
            c[i] = {y, i};
            if (y & 1) a[++n] = c[i];
            else b[++m] = c[i];
        }
        sort(c + 1, c + x + 1);
        fi(i, 1, n) fi(j, i + 1, n){
            int gt = (a[i].first + a[j].first) >> 1;
            int ans = lower_bound(c + 1, c + x + 1, make_pair(gt, a[j].second))
                    - upper_bound(c + 1, c + x + 1, make_pair(gt, a[i].second));
            res += max(ans, 0);
        }
        fi(i, 1, m) fi(j, i + 1, m){
            int gt = (b[i].first + b[j].first) >> 1;
            int ans = lower_bound(c + 1, c + x + 1, make_pair(gt, b[j].second))
                    - upper_bound(c + 1, c + x + 1, make_pair(gt, b[i].second));
            res += max(ans, 0);
        }
        cout << res << '\n';
    }

}
