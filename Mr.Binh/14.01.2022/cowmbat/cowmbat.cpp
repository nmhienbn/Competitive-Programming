#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define rep(i, n) for (int i = 0, _n = n; i < _n; i++)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "cowmbat"
const int maxn = 1e5 + 5;
using namespace std;

int n, m, k;
int a[26][26], c[maxn][26], f[maxn][26], g[maxn];
string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m >> k >> s;
    rep(i, m) rep(j, m)
        cin >> a[i][j];
    rep(k, m) rep(i, m) rep(j, m)
            a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
    fi(i, 1, n){
        int now = s[i - 1] - 'a';
        rep(j, m){
            c[i][j] = c[i - 1][j] + a[now][j];
        }
    }
    memset(f, 60, sizeof f);
    memset(g, 60, sizeof g);
    g[0] = 0;
    fi(i, 1, n){
        rep(j, m){
            f[i][j] = min(f[i][j], f[i - 1][j] + c[i][j] - c[i - 1][j]);
            if (i >= k)
                f[i][j] = min(f[i][j], c[i][j] - c[i - k][j] + g[i - k]);
            g[i] = min(g[i], f[i][j]);
        }
    }
    cout << g[n];
}
