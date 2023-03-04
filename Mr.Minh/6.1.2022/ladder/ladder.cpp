#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "ladder"
const int maxn = 1005;
using namespace std;

int m, n, k, a[maxn], f[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> m >> n >> k;
    fi(i, 1, k){
        int u, v;
        cin >> u >> v;
        a[u] = max(a[u], v);
    }
    f[1] = a[1];
    f[2] = max(a[1], a[2]);
    fi(i, 3, n){
        f[i] = min({f[i - 3] + max({a[i], a[i - 1], a[i - 2]}),
                    f[i - 2] + max(a[i], a[i - 1]),
                    f[i - 1] + a[i]});
    }
    cout << f[n];
}
