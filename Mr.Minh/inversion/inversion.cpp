#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "inversion"
const int maxn = 1e6+5, mod = 1e9+7;
using namespace std;

int n, nt, a[maxn];
ll m, res;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> nt;
    while (nt--){
        cin >> n >> m;
        if (m > 1ll*n*(n-1)/2){
            cout << "-1\n";
            continue;
        }
        fi(i, 1, n){
            if (m >= 1ll*(n-i)*(n-i-1)/2){
                a[i] = m - 1ll*(n-i)*(n-i-1)/2 + i;
                int id = i;
                fid(j, n, i) if (j != a[i]){
                    a[++id] = j;
                }
                break;
            }
            else a[i] = i;
        }
        res = 0;
        fid(i, n, 1){
            if (a[i] > n) cout << -1 << ' ';
            res = (res*2 + a[i]) % mod;
        }
        cout << res << '\n';
    }
}
