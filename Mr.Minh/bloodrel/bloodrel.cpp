#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "bloodrel"
const int maxn = 66000;

using namespace std;

int n, a[maxn], b[maxn];
ll res, cnt1, cnt2, cnt3;

void sub1(){
    fi(i, 2, n){
        fi(j, 1, i - 1){
            res += __builtin_popcount(a[i] ^ a[j]) <= 2;
        }
    }
    cout << res;
    exit(0);
}

void xuli(int a[], ll& x){
    int tg = 1;
    fi(i, 2, n){
        if (a[i] == a[i - 1]) tg++;
        else x += 1ll * tg * (tg - 1) / 2, tg = 1;
    }
    x += 1ll * tg * (tg - 1) / 2;
}

void sub2(){
    sort(a + 1, a + n + 1);
    xuli(a, cnt1);
    fi(j, 0, 29){
        fi(i, 1, n){
            if (gb(a[i], j)) b[i] = a[i] - (1 << j);
            else b[i] = a[i];
        }
        sort(b + 1,  b + n + 1);
        xuli(b, cnt2);
    }
    fi(u, 1, 29) fi(v, 0, u - 1){
        fi(i, 1, n){
            b[i] = a[i];
            if (gb(a[i], u)) b[i] -= (1 << u);
            if (gb(a[i], v)) b[i] -= (1 << v);
        }
        sort(b + 1,  b + n + 1);
        xuli(b, cnt3);
    }
    cnt2 -= cnt1 * 30;
    cnt3 -= cnt2 * 29 + cnt1 * 435;
    res = cnt1 + cnt2 + cnt3;
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i];
    if (n <= 2000) sub1();
    sub2();
}
