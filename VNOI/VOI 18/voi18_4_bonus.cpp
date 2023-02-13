#include <bits/stdc++.h>
#define gb(x, i) (((x) >> (i)) & 1)
using namespace std;

struct dl {
    int u, v, x, y; 
};

const int maxn = 505;
int n, m, r, p;
long long a[maxn][maxn], res, ans;
dl f[32];
pair<int,int> x[maxn];

long long get(dl b){
    if (b.x < b.u || b.y < b.v) return 0;
    return a[b.x][b.y] + a[b.u - 1][b.v - 1] - a[b.u - 1][b.y] - a[b.x][b.v - 1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> m >> r >> p;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    }
    int M = (1 << p) - 1;
    for (int rep = 1; rep <= m; rep++) {
        ans = 0;
        for (int i = 0; i < p; i++) {
            cin >> x[i].first >> x[i].second;
        }
        sort(x, x + p);
        for (int i = 0; i < p; i++) {
            f[1 << i] = {x[i].first, x[i].second, x[i].first + r - 1, x[i].second + r - 1};
        }
        for (int x = 1; x <= M; x++) {
            int k = __builtin_popcount(x);
            if (k > 1){
                for (int i = p - 1; i >= 0; i--) {
                    if (gb(x, i)){
                        dl& A = f[x ^ (1 << i)];
                        dl& B = f[1 << i];
                        f[x] = {max(A.u, B.u), max(A.v, B.v), min(A.x, B.x), min(A.y, B.y)};
                        if (k & 1) ans += get(f[x]);
                        else ans -= get(f[x]);
                        break;
                    }
                }
            }
            else ans += get(f[x]);
        }
        if (ans > res) res = ans;
    }
    cout << res;
    return 0;
}
