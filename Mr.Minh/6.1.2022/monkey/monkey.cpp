#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "monkey"
const int maxn = 1e5 + 5,
            ngg[8] = {0, -1, -1, -1, 0, 1, 1, 1},
            doc[8] = {1, 1, 0, -1, -1, -1, 0, 1};
using namespace std;

int n, dx, dy, sx, sy;
ll res;
string s;
int a[maxn], y[maxn], f[maxn][8], g[maxn][8];

ll sq(int x, int y){
    x = sx - x;
    y = sy - y;
    return 1ll * x * x + 1ll * y * y;
}

void minimize(ll & x, ll y){
    if (x > y) x = y;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> dx >> dy >> sx >> sy >> n >> s;
    sx -= dx;
    sy -= dy;
    fi(i, 1, n){
        a[i] = (a[i - 1] + s[i - 1] - '0') % 8;
        fi(j, 0, 7){
            f[i][j] = f[i - 1][j] + ngg[(a[i] + j) % 8];
            g[i][j] = g[i - 1][j] + doc[(a[i] + j) % 8];
        }
    }
    res = sq(f[n][0], g[n][0]);
    fi(i, 0, n){
        fi(j, 1, 7) {
            minimize(res, sq(f[n][j] - f[i][j] + f[i][0], g[n][j] - g[i][j] + g[i][0]));
        }
    }
    cout << fixed << setprecision(3) << sqrt(res);
}
