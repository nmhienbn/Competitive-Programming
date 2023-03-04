#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "permute"
const int maxn = 400005, mod = 998244353;

using namespace std;

int theta, n, cnt1, cntPos, gt[maxn], a[maxn], C[maxn], res;
bool kt[maxn];

ll binpow(ll a, int k){
    if (k == 1) return a % mod;
    ll tg = binpow(a, k >> 1);
    if (k & 1) return (tg * tg % mod) * a % mod;
    return tg * tg % mod;
}

void calc(){
    gt[0] = 1;
    fi(i, 1, n){
        gt[i] = 1ll * gt[i-1] * i % mod;
    }
    C[0] = 1;
    fi(i, 1, cntPos){
        C[i] = 1ll * C[i-1] * binpow(i, mod - 2) % mod;
        C[i] = 1ll * C[i] * (cntPos + 1 - i) % mod;
    }
}

void add(int& x, int y){
    x += y;
    if (x >= mod) x -= mod;
}

void sub(int& x, int y){
    x -= y;
    if (x < 0) x += mod;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> theta >> n;
    fi(i, 1, n){
        cin >> a[i];
        if (a[i] == -1) cnt1++;
        else kt[a[i]] = 1;
    }
    fi(i, 1, n){
        if (a[i] == -1 && !kt[i]) cntPos++;
    }
    calc();
    fi(i, 0, cntPos){
        cout <<  1ll * C[i] * gt[cnt1-i] % mod << ' ';
        if (i & 1) sub(res, 1ll * C[i] * gt[cnt1-i] % mod);
        else add(res, 1ll * C[i] * gt[cnt1-i] % mod);
    }
    cout << res;
}
