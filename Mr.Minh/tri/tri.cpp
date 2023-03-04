#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "tri"
const int maxn = 2005;
using namespace std;

int m, n, k, a[maxn][maxn];
ll s[maxn * 2][maxn], b[maxn][maxn], res = -1e18;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> m >> n >> k;
    fi(i, 1, m) fi(j, 1, n){
        cin >> a[i][j];
        s[i - j + n][j] = s[i - j + n][j - 1] + a[i][j];
        b[i][j] = b[i - 1][j] + a[i][j];
    }
    fi(i, 1, m - k + 1){
        ll sum = 0;
        fi(j, 1, k){
            sum += b[i + k - 1][j] - b[i + j - 2][j];
        }
        res = max(res, sum);
        fi(j, k + 1, n){
            sum += s[i + k - 1 - j + n][j] - s[i + k - j - 1 + n][j - k];
            sum -= b[i + k - 1][j - k] - b[i - 1][j - k];
            res = max(res, sum);
        }
    }
    cout << res;
}
