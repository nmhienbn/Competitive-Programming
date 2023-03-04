#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "aseq"
const int maxn = 1e5 + 5;
using namespace std;

int n, L, R;
ll res, a[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> L >> R;
    n++;
    fi(i, 2, n) cin >> a[i], a[i] += a[i - 1];
    sort(a + 1, a + n + 1);
    fi(i, 1, n){
        res += upper_bound(a + 1, a + i, a[i] - L) - lower_bound(a + 1, a + i, a[i] - R);
    }
    cout << res;
}
