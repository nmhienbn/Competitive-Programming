#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define getbit(x,i) (((x) >> (i)))
#define pii pair <int, int>
#define pb push_back
#define Irelia "kstr"
const int maxn = 5e4+5, maxm = 15, mod = 123457;
using namespace std;

int n, k, a[maxn], cnt[300], b[maxn], now, pre, vt;
ll res;

ll binpow(ll a, int k){
    if (k == 0) return 1;
    ll tg = binpow(a, k >> 1);
    if (k & 1) return (tg * tg % mod) * a % mod;
    return tg*tg % mod;
}

void xuli(int x, int now){
    int dem = 0;
    //int hs = kt%2 ? -1 : 1;
    fi(i, 0, 9) if ((now >> i) & 1) cout << i;
    fi(i, 1, 255) if ((i & now) == 0 && (i & x) == x) dem += cnt[i];
    if (dem > 0) res = (res + binpow(2, dem)) % mod;
    cout << ' ' << res << '\n';
}

void ql(int x, int i){
    fi(j, pre+1, 9) if ((x >> j) & 1){
        pre = j;
        now += (1 << j);
        if (i >= k && i < vt) xuli(x-now, now);
        ql(x, i+1);
        now -= (1 << j);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> k >> n;
    fi(i, 1, n){
        int t;
        cin >> t;
        b[i] = t;
        while (t--){
            int u;
            cin >> u;
            a[i] += (1 << u);
        }
        cnt[a[i]]++;
    }
    fi(i, 1, n){
        cnt[a[i]]--;
        if (b[i] < k) continue;
        vt = b[i];
        pre = -1;
        ql(a[i], 1);
        int dem = 0;
        fi(i, 1, 255) if ((i & now) == 0) dem += cnt[i];
        res = (res + binpow(2, dem)) % mod;
    }
    cout << res % mod;
}
