#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "d2p"
const int maxn = 4e5+5, mod = 1e9 + 7;
using namespace std;

int gt[maxn], nt, n, k;

int binpow(int a, int k){
    if (k == 0) return 1;
    int tg = binpow(a, k >> 1);
    if (k & 1) return (1ll * tg * tg % mod) * a % mod;
    return 1ll * tg *  tg % mod;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    gt[0] = 1;
    fi(i, 1, maxn - 5){
        gt[i] = 1ll * gt[i - 1] * i % mod;
    }
    cin >> nt;
    while (nt--){
        cin >> n >> k;
        cout << (1ll * gt[n * 2] * binpow(1ll * gt[k] * gt[n - k] % mod, mod - 2) % mod) * binpow(2, mod - 1 - n) % mod << '\n';
    }
}
