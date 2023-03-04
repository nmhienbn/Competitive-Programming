#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "special"
const int maxn = 1e5 + 5;

using namespace std;

int n, a[maxn], b[maxn], f[maxn], g[maxn], t, k, cnt;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> t;
    while (t--){
        cin >> n;
        fi(i, 1, n) cin >> a[i];
        //LIS-------------------------------
        k = 0;
        fi(i, 1, n){
            int d = 1, c = k;
            while (d <= c){
                int g = (d + c) >> 1;
                if (b[g] > a[i]) c = g - 1;
                else d = g + 1;
            }
            if (d == k + 1) b[++k] = 1e9;
            b[d] = min(b[d], a[i]);
            f[i] = d;
        }
        //LDS-------------------------------
        k = 0;
        fid(i, n, 1){
            int d = 1, c = k;
            while (d <= c){
                int g = (d + c) >> 1;
                if (b[g] < a[i]) c = g - 1;
                else d = g + 1;
            }
            if (d == k + 1) b[++k] = 0;
            b[d] = max(b[d], a[i]);
            g[i] = d;
        }
        //kq--------------------------------
        cnt = 0;
        fi(i, 1, n){
            if (f[i] + g[i] == k + 1) b[++cnt] = a[i];
        }
        sort(b + 1, b + cnt + 1);
        fi(i, 1, cnt) cout << b[i] << ' ';
        cout << '\n';
    }

}
