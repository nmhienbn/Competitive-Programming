#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "bonus"
const int maxn = 505;
using namespace std;

struct dl {
    int u, v, x, y; //(u, v) < (x, y)
};

int n, m, r, p;
ll a[maxn][maxn], res, ans;
dl f[32];
pii x[maxn];

ll get(dl b){
    if (b.x < b.u || b.y < b.v) return 0;
    return a[b.x][b.y] + a[b.u - 1][b.v - 1] - a[b.u - 1][b.y] - a[b.x][b.v - 1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m >> r >> p;
    fi(i, 1, n) fi(j, 1, n){
        cin >> a[i][j];
        a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
    }
    int M = (1 << p) - 1;
    fi(rep, 1, m){
        ans = 0;
        fi(i, 0, p - 1){
            cin >> x[i].first >> x[i].second;
        }
        sort(x, x + p);
        fi(i, 0, p - 1){
            f[1 << i] = {x[i].first, x[i].second, x[i].first + r - 1, x[i].second + r - 1};
        }
        fi(x, 1, M){
            int k = __builtin_popcount(x);
            if (k > 1){
                fid(i, p - 1, 0) if (gb(x, i)){
                    dl A = f[x ^ (1 << i)];
                    dl B = f[1 << i];
                    f[x] = {max(A.u, B.u), max(A.v, B.v), min(A.x, B.x), min(A.y, B.y)};
                    if (k & 1) ans += get(f[x]);
                    else ans -= get(f[x]);
                    break;
                }
            }
            else ans += get(f[x]);
        }
        if (ans > res) res = ans;
    }
    cout << res;
}
