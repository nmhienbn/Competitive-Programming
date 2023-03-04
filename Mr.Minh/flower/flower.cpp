#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "flower"
const int maxn = 1005;

using namespace std;

int n, m, a[maxn][maxn];
ll f[maxn][maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, n){
        fi(j, 1, m){
            cin >> a[i][j];
        }
    }
    fi(i, 1, n) f[i][i-1] = -1e18;
    fi(i, 1, n){
        fi(j, i, m){
            //cout << a[i][j] << ' ';
            f[i][j] = max(f[i][j - 1], f[i - 1][j - 1] + a[i][j]);
        }
    }
    //fi(i, 1, n) {fi(j, 1, m) cout << f[i][j] << ' '; cout << endl;}
    cout << f[n][m];
}
