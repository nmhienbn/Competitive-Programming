#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "copy"
const int maxn = 3e5+5;
const ll maxx = 1e18;
using namespace std;

int m, n;
ll res = maxx, a[maxn], b[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> m >> n;
    fi(i, 1, m) cin >> a[i];
    fi(i, 1, n) cin >> b[i];
    sort(a+1, a+m+1);
    sort(b+1, b+n+1);
    fi(i, 1, m) a[i] += a[i-1];
    fi(i, 1, n) b[i] += b[i-1];
    fi(i, 1, n){
        if ((maxx - b[n-i]) / i > a[m]) res = min(res, a[m] * i + b[n - i]);
    }
    fi(i, 1, m){
        if ((maxx - a[m-i]) / i > b[n]) res = min(res, b[n] * i + a[m - i]);
    }
    cout << res;
}
