#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "gcdlcm"
const int maxn = 15e5+5, mod = 998244353;
using namespace std;

int n, m, k, a[maxn], mu[maxn];

void Erathosenes(){
    fi(i, 1, 15e5) a[i] = i;
    fi(i, 2, 1230) if (a[i] == i){
        for (int j = i * i; j <= 15e5; j += i){
            a[j] = i;
        }
    }
}

int binpow(int a, int k){
    if (k == 0) return 1;
    int tg = binpow(a, k >> 1);
    if (k & 1) return (1ll * tg * tg % mod) * a % mod;
    return 1ll * tg * tg % mod;
}

void add(int& x, int y){
    x += y;
    if (x >= mod) x -= mod;
}
void sub(int& x, int y){
    x -= y;
    if (x < 0) x += mod;
}

ll res = 1;

int f(int u){
    int ans = binpow(u+1, k);
    int v = binpow(u, k);
    sub(ans, v);
    sub(ans, v);
    add(ans, binpow(u-1, k));
    return ans;
}

void nhap(int i){
    int x;
    cin >> x;
    while (x > 1){
        int p = a[x];
        while (x % p == 0){
            mu[p] += i;
            x /= p;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    Erathosenes();
    cin >> n >> m >> k;
    fi(i, 1, n){
        nhap(-1);
    }
    fi(i, 1, m){
        nhap(1);
    }
    fi(i, 2, maxn-5){
        if (mu[i] > 0){
            res = (res * f(mu[i])) % mod;
        }
        else if (mu[i] < 0){
            res = 0;
            break;
        }
    }
    cout << res;
}
