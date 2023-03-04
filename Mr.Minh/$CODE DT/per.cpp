#include <bits/stdc++.h>
#define Irelia "per"
const int mod = 1e9 + 7;

using namespace std;

int n, f[105];
long long res = 1;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    f[0] = 1, f[1] = 0;
    for (int i = 2; i <= n; i++)
        f[i] = 1LL * (i - 1) * (f[i - 1] + f[i - 2]) % mod;
    cout << f[n];
}
