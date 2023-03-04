#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "analyse"
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
using namespace std;

int q, n, p[maxn];

int mu(int a, int k){
    int res = 1;
    int lt = a;
    while (k > 0){
        if (k & 1) res = 1LL * res * lt % mod;
        lt = 1LL * lt * lt % mod;
        k >>= 1;
    }
    return res;
}

unordered_map<int, int> f;

int calc(int u){
    if (f[u]) return f[u];
    int ans = mu(2, u - 1) - 1;
    fi(i, 2, sqrt(u)) if (u % i == 0){
        ans -= calc(i);
        if (i * i != u) ans -= calc(u / i);
        while (ans < 0) ans += mod;
    }
    return f[u] = ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> q;
    f[1] = 1;
    while (q--){
        cin >> n;
        cout << calc(n) << '\n';
    }

}
