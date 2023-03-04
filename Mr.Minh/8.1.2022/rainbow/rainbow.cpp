#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "rainbow"
const int maxn = 505, mod = 1e9 + 9;
using namespace std;

int n, k, res;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
//    freopen(Irelia".inp", "r", stdin);
//    freopen(Irelia".out", "w", stdout);
    cin >> n >> k;
    if (n == 1){
        cout << 0;
        exit(0);
    }
    if (n == 2){
        cout << k;
        exit(0);
    }
    if (k <= 2){
        cout << 0;
        exit(0);
    }
    res = 1ll * k * (k - 1) % mod;
    fi(i, 4, n){
        res = 1ll * res * (k - 2) % mod;
    }
    cout << res;
}
