#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "fib2"
const int maxn = 50;
using namespace std;

int n, k, f[maxn], g[maxn], nt;

int calc(int n, int k){
    if (k == f[n]) return g[n];
    if (k == 0) return 0;
    if (k >= f[n - 2]) return g[n - 2] + calc(n - 1, k - f[n - 2]);
    return calc(n - 2, k);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    f[0] = f[1] = 1;
    fi(i, 2, 45) f[i] = f[i - 1] + f[i - 2];
    g[0] = 1, g[1] = 0;
    fi(i, 2, 45) g[i] = g[i - 1] + g[i - 2];
    cin >> nt;
    while (nt--){
        cin >> n >> k;
        cout << calc(n, k) << '\n';
    }
}
