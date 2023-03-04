#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL);
#define Irelia "flowers"
const int maxn = 1e6+5, MAX = 1e6;

using namespace std;

int n, m, k, t, p, gt[maxn], cnt[maxn];

int pw(int a, int k){
    if (k == 0) return 1;
    int tg = pw(a, k >> 1);
    if (k & 1) return (1ll * tg * tg % p) * a % p;
    return 1ll * tg * tg % p;
}

int C(int n, int k, int p){
    return (1ll * gt[n] * pw(gt[k], p-2) % p) * pw(gt[n-k], p-2) % p;
}

int C(int n, int k){
    int ans = 1;
    fi(i, 0, k-1){
        ans = 1ll * ans * (n - i) % p;
    }
    return 1ll * ans * pw(gt[k], p-2) % p;
}

void sub2(){
    gt[0] = 1;
    fi(i, 1, MAX) gt[i] = 1ll * gt[i-1] * i % p;
    while (t--){
        cin >> n >> m >> k;
        cout << (1ll * C(n-1, k, p) * m % p) * pw(m-1, k) % p << '\n';
    }
    exit(0);
}

void sub3(){
    gt[0] = 1;
    fi(i, 1, MAX) gt[i] = 1ll * gt[i-1] * i % p;
    while (t--){
        cin >> n >> m >> k;
        cout << (1ll * C(n-1, k) * m % p) * pw(m-1, k) % p << '\n';
    }
    exit(0);
}

void process(int n, int val){
    while (n > 1){
        int p = gt[n];
        cnt[p] += val;
        n /= p;
    }
}
void sub4(){
    fi(i, 1, MAX) gt[i] = i;
    fi(i, 2, 1000) if (gt[i] == i){
        for (int j = i * i; j <= MAX; j += i){
            gt[j] = i;
        }
    }
    while (t--){
        fi(i, 1, MAX) cnt[i] = 0;
        cin >> n >> m >> k;
        int ans = 1ll * m * pw(m-1, k) % p;
        if (k * 2 > n - 1){
            k = n - 1 - k;
        }
        fi(i, 1, k){
            process(n - i, 1);
            process(i, -1);
        }
        fi(i, 2, MAX) if (cnt[i] > 0) ans = 1ll * ans * pw(i, cnt[i]) % p;
        cout << ans << '\n';
    }
    exit(0);
}

int main(){
    faster
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> t >> p;
    if (t != 50){
        sub2();
    }
    if (p == 998244353){
        sub3();
    }
    sub4();
}
