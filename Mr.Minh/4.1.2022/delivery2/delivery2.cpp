#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "delivery2"
const int maxn = 1e6 + 5;
using namespace std;

int n, a[maxn];
ll b[maxn], c[maxn], e[maxn], f[maxn], res = 1e18;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i];
    fi(i, 2, n) b[i] = b[i - 1] + a[i];
    fi(i, 1, n) c[i] = c[i - 1] + b[i];
    fid(i, n - 1, 1) e[i] = e[i + 1] + a[i];
    fid(i, n, 1) f[i] = f[i + 1] + e[i];
    fi(i, 0, n) res = min(res, c[i] + f[i + 1]);
//    fi(i, 1, n) cout << b[i] << ' '; cout << endl;
//    fi(i, 1, n) cout << e[i] << ' '; cout << endl;
//    fi(i, 1, n) fi(j, 1, n) if (c[i] + f[j] == res) cout << i << ' ' << j << '\n';
    cout << res;
}
