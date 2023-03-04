#include <bits/stdc++.h>
#define maximize(x, y) x = x < y ? y : x
using namespace std;

const int maxn = 2005;

int n, a[maxn], res, b[maxn];
int f[maxn][1050], g[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int cnt = 0;
    a[0] = -1;
    for (int i = 1; i <= n; i++){
        if (a[i] != a[i - 1]){
            a[++cnt] = a[i];
        }
        b[cnt]++;
    }
    swap(n, cnt);
    for (int i = 1; i <= n; i++){
        for (int j = max(1, i - 9); j < i; j++){
            if (a[i] - a[j] == 1 || a[i] - a[j] == 8 || a[i] - a[j] == 9){
                g[i] |= (1 << (i - j - 1));
            }
        }
    }
    f[1][0] = 0;
    f[1][1] = b[1];
    for (int i = 2; i <= n; i++){
        for (int j = 0; j <= 511; j++){
            int nex = (j & 255) << 1;
            maximize(f[i][nex], f[i - 1][j]);
            if (!(j & g[i])) maximize(f[i][nex | 1], f[i - 1][j] + b[i]);
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= 511; j++){
            res = max(res, f[i][j]);
        }
    }
    cout << cnt - res;
}
