#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define minimize(x,y) x = x > y ? y : x
#define ll long long
#define Irelia "game"
const int maxn = 2005;
const ll INF = 1e18;
using namespace std;

int n, m;
int a[maxn], b[maxn];
ll f[maxn][maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, n) cin >> a[i], a[i]--;
    fi(i, 1, m) cin >> b[i], b[i]--;
    fi(i, 0, n) fi(j, 0, m) f[i][j] = INF;
    f[0][0] = 0;
    fi(i, 1, n){
        fi(j, 1, m){
            f[i][j] = min({f[i - 1][j], f[i - 1][j - 1], f[i][j - 1]}) + 1ll * a[i] * b[j];
        }
    }
    cout << f[n][m];
}
