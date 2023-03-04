#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define maximize(x, y) x = x < y ? y : x
#define LCM(x, y) 1ll * x * y / __gcd(x, y)
#define pb push_back
#define ll long long
#define Irelia "monodigit"
const int maxn = 1e6 + 5, INF = 2e9;
using namespace std;

int L, n, a[15], b[15], id;
ll res;
int luu[maxn * 10];

int calc(int n){
    if (luu[n]) return luu[n];
    if (n % 2 == 0 || n % 5 == 0) return luu[n] = INF;
    int cnt = 1, lt = 10;
    while (cnt < n){
        if (lt % n == 1) return luu[n] = cnt;
        lt = lt * 10 % n;
        cnt++;
    }
    return luu[n] = INF;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    luu[1] = 1;
    cin >> L >> n;
    fi(i, 1, n) cin >> a[i];
    fid(x, 9, 1){
        fi(i, 1, n){
            b[i] = calc(9 * a[i] / __gcd(a[i], x));
        }
        ll ans = 0;
        fi(i, 1, n) fi(j, i + 1, n) if (b[i] != INF && b[j] != INF){
            ll tmp = LCM(b[i], b[j]);
            maximize(ans, L / tmp * tmp);
        }
        if (ans > res) {
            res = ans;
            id = x;
        }
    }
    if (res == 0) res = 1, id = 0;
    cout << res << ' ' << id;

}
