#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "robot"
const int maxn = 1e5 + 5;
using namespace std;

int n, x, y, z, a[maxn], b[maxn], sa, sb;
int u, v, c[maxn], d[maxn];
ll res, f[105][105];

void sub1(){
    z = min(z, x + y);
    fi(i, 1, n) if (a[i]) c[++u] = i;
    fi(i, 1, n) if (b[i]) d[++v] = i;
    if (u > v){
        fi(i, 1, u) swap(c[i], d[i]);
        swap(u, v);
    }
    fi(i, 1, u) f[0][i] = 1e18;
    fi(i, 1, v){
        fi(j, 1, u){
            f[i][j] = min(f[i - 1][j], f[i - 1][j - 1] + 1ll * z * abs(c[i] - d[j]));
        }
    }
    cout << res + f[u][v];
    exit(0);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> x >> y >> z;
    fi(i, 1, n) cin >> a[i], sa += a[i];
    fi(i, 1, n) cin >> b[i], sb += b[i];
    if (sa < sb) res += 1ll * x * (sb - sa);
    if (sa > sb) res += 1ll * x * (sa - sb);
    if (n <= 100) sub1();
    cout << res;
}
