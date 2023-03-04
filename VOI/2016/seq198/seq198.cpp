#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define maximize(x, y) x = x < y ? y : x
#define Irelia "seq198"
const int maxn = 2005;
using namespace std;

int n, a[maxn], res, b[maxn];
int f[maxn][1050], g[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    int cnt = 0;
    a[0] = -1;
    fi(i, 1, n){
        if (a[i] != a[i - 1]){
            a[++cnt] = a[i];
        }
        b[cnt]++;
    }
    swap(n, cnt);
    //fi(i, 1, n) cout << a[i] << ' ' << b[i] << '\n';
    fi(i, 1, n){
        fi(j, max(1, i - 9), i - 1) if (a[i] - a[j] == 1 || a[i] - a[j] == 8 || a[i] - a[j] == 9){
            g[i] |= (1 << (i - j - 1));
        }
        //cout << g[i] << ' ';
    }
    //fi(i, 1, n) fi(j, 0, 511) f[i][j] = -1e9;
    f[1][0] = 0;
    f[1][1] = b[1];
    fi(i, 2, n){
        fi(j, 0, 511){
            int nex = (j & 255) << 1;
            maximize(f[i][nex], f[i - 1][j]);
            if (!(j & g[i])) maximize(f[i][nex | 1], f[i - 1][j] + b[i]);
        }
    }
    int res = 0;
    fi(i, 1, n) fi(j, 0, 511) res = max(res, f[i][j]);
    cout << cnt - res;
}
