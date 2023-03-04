#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "llgame"
const int maxn = 105, maxk = 1005, mod = 1e9 + 7;
using namespace std;

int binpow(int a, int k){
    if (k == 1) return a;
    int tg = binpow(a, k >> 1);
    if (k & 1) return (1ll * tg * tg % mod) * a % mod;
    return 1ll * tg * tg % mod;
}

int n, k, a;
ll f[maxn][maxk], C[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> k;
    fi(i, 1, n){
        cin >> a;
        if (a < 0) k += a;
        else k -= a;
    }
    if (k <= 0){
        cout << 0;
        exit(0);
    }
    C[0] = 1;
    fi(i, 1, n){
        C[i] = C[i - 1] * (4 * i - 2) % mod;
        C[i] = C[i] * binpow(i, mod - 2) % mod;
    }
    fi(i, 1, n){
        f[i][0] = 1;
        fi(j, 1, k){

        }
    }

}
