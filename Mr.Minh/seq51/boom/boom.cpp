#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "boom"
const int maxn = 305;
using namespace std;

int n, m, a[maxn], b[maxn], c[maxn];
ll res;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, m) cin >> a[i] >> b[i] >> c[i];
    fi(i, 0, n - 1) fi(j, 0, n - 1){
        ll ans = 0;
        fi(k, 1, m){
            ans += max(0, c[k] - max(abs(a[k] - i), abs(b[k] - j)));
        }
        res = max(res, ans);
    }
    cout << res;
}
