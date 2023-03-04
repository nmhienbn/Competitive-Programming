#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "diamond"
const int maxn = 755;
using namespace std;

int m, n, threshold, a[maxn][maxn], now;
int f[2][maxn][maxn], res;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> m >> n >> now >> threshold;
    fi(i, 1, m) fi(j, 1, n){
        now = (now * 25173 + 13849) % 65536;
        a[i][j] = now >= threshold;
    }
    fi(i, 1, m) fi(j, 1, n) if (a[i][j]){
        f[0][i][j] = f[0][i - 1][j - 1] + 1;
    }
    fi(i, 1, m) fid(j, n, 1) if (a[i][j]){
        f[1][i][j] = f[1][i - 1][j + 1] + 1;
    }
    fi(i, 1, m) fi(j, 1, n){
        fi(t, 0, n / 2 + 1){
            int k = j + t * 2;
            if (k > n || t > i || t + i > m + 1) break;
            if (f[1][i][j] > t && f[0][i + t][j + t] > t && f[0][i][k] > t && f[1][i + t][j + t] > t){
                res = max(res, t + 1);
            }
        }
    }
    cout << res;
}
