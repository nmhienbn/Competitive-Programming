#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL);
#define NunuAndWillump "wordtab"
const int maxn = 5001, maxr = 101, mod = 1e9+7, base = 29;

using namespace std;

int r, c, n, m, b[maxr][maxn], ss, d[maxn],
    t, res, id, hn, ht, hc, hnc;
char a[maxr][maxr], x;

int sub(int a, int b){
    a -= b;
    if (a < 0) return a+mod;
    return a;
}

int binpow(int a, int k){
    if (k == 0) return 1;
    int tg = binpow(a, k >> 1);
    tg = 1ll*tg*tg % mod;
    if (k&1) return 1ll*tg*a % mod;
    return tg;
}

int main(){
    //faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    scanf("%d %d", &r, &c);
    fi(i, 1, r){
        scanf("\n");
        fi(j, 1, c){
            scanf("%c", &a[i][j]);
        }
    }
    scanf("%d %d", &m, &n);
    hn = binpow(base, n);
    hc = binpow(base, c);
    hnc = binpow(base, n-c);
    ht = binpow(base, n*(r-1));
    fi(i, 1, r){
        ss = 1ll*ss*hnc % mod;
        fi(j, 1, c){
            ss = (1ll*ss*base + a[i][j]) % mod;
        }
    }
    fi(i, 1, r-1){
        scanf("\n");
        fi(j, 1, n){
            scanf("%c", &x);
            b[i][j] = (1ll*b[i][j-1]*base + x) % mod;
            d[j] = (1ll*d[j]*hn + b[i][j]) % mod;
        }
    }
    fi(i, r, m){
        scanf("\n");
        fi(j, 1, n){
            id = (i-1) % r + 1;
            scanf("%c", &x);
            d[j] = sub(d[j], 1ll*b[id][j]*ht % mod);
            b[id][j] = (1ll*b[id][j-1]*base + x) % mod;
            d[j] = (1ll*d[j]*hn + b[id][j]) % mod;
        }
        fi(j, c, n){
            if (sub(d[j], 1ll*d[j-c]*hc % mod) == ss){
                res++;
            }
        }
    }
    printf("%d", res);
}
