#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "prizes"
const int maxn = 1e5+5;

using namespace std;

int n, m, k;
ll f[maxn][20], s[maxn];
ll get(int u, int v){
    if(u > v) return 0;
    int k = log2(v - u + 1);
    return max(f[u][k], f[v - (1 << k) + 1][k]);
}
int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> k;
    m = n - k + 1;
    fi(i, 1, n){
        int a;
        cin >> a;
        s[i] = s[i - 1] + a;
    }
    fi(i, 1, m) f[i][0] = s[i + k - 1] - s[i - 1];
    fi(j, 1, log2(m))
        fi(i, 1, m - (1 << j) + 1)
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
    ll res = 1e18;
    fi(i, 1, m)
        res = min(res, max(get(1, i - 1), get(i + k, m)));
    cout << res;
}
