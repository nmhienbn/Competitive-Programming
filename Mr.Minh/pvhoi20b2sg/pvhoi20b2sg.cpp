#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define NunuAndWillump "pvhoi20b2sg"
const int maxn = 1e5+5, mod = 998244353;

using namespace std;

int n, m, t, k, a[13], L[maxn], s[maxn];
ll res = 0;

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n >> m >> t >> k;
    fi(i, 1, n){
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    if (n == 1){
        ll ans = 1;
        m++;
        fi(i, 1, t){
            ans = (ans * m) % mod;
        }
        cout << ans;
        exit(0);
    }
    if (a[1] + m*t + k < a[n]){
        cout << 0;
        exit(0);
    }
    int maxx = 0;
    L[0] = 1;
    fi(i, 1, t){
        fid(w, maxx, 0){
            fid(j, m, 0){
                L[w+j] = (L[w+j] + L[w]) % mod;
            }
        }
        maxx += m;
        L[0] = 1;
    }
    s[0] = 1;
    fi(i, 1, maxx) s[i] = (s[i-1] + L[i]) % mod;
    if (n == 2){
        fi(i, 0, maxx){
            int d = max(a[1] - a[2] - k, 0), c = min(a[1] + k - a[2], maxx);
            if (c >= d){
                ll tg = (s[c] - (d > 0 ? s[d-1] : 0) + mod) % mod;
                res = (res + (tg*L[i]) % mod) % mod;
            }
            a[1]++;
        }
    }
    else if (k == 0){
        fi(j, a[n], a[1] + maxx){
            ll ans = 1;
            fi(i, 1, n){
                ans *= L[min(j - a[i], maxx)];
                ans %= mod;
            }
            res += ans;
            res %= mod;
        }
    }
    cout << res;
}
