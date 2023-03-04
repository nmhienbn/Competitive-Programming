#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "cryptkey"
const int maxn = 5e4 + 5;
using namespace std;

int nt, n;
ll a[maxn], p[maxn], b[maxn], k;

void PTTSNT(int& cnt, ll k){
    for (int i = 2;1LL * i * i <= k; i++) if (k % i == 0){
        ll lt = 1;
        while (k % i == 0){
            lt *= i;
            k /= i;
        }
        p[++cnt] = lt;
    }
    if (!cnt || k > 1) p[++cnt] = k;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    //freopen(Irelia".inp", "r", stdin);
    //freopen(Irelia".out", "w", stdout);
    cin >> nt;
    while (nt--){
        cin >> n;
        fi(i, 1, n) cin >> a[i];
        cin >> k;
        int cnt = 0;
        PTTSNT(cnt, k);
        fi(i, 1, cnt) b[i] = 0;
        fi(i, 1, n){
            fi(j, 1, cnt){
                if (a[i] % p[j] == 0){
                    b[j] = __gcd(b[j], a[i]);
                }
            }
        }
        bool ok = 1;
        fi(i, 1, cnt) if (!b[i] || k % b[i]){
            ok = 0;
            break;
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
}
