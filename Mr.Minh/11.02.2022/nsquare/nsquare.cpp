#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "nsquare"
const int maxn = 1005;
using namespace std;

int n, k;
int x;
ll a[maxn][maxn], b[maxn][maxn], res = 1e9;

ll sum(int u, int v, int l, int r){
    return a[v][r] - a[v][l - 1] - a[u - 1][r] + a[u - 1][l - 1];
}

ll get(int i, int l, int r){
    return b[i + r - l][r] - b[i - 1][l - 1] - sum();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> k;
    fi(i, 1, n) fi(j, 1, n){
        cin >> x;
        a[i][j] = x + a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        b[i][j] = x + b[i - 1][j - 1] + b[i - 1][j] - b[max(0, i - 2)][j - 1];
    }
    fi(i, 1, n - k + 1){
        fi(j, 1, n - k + 1){
            res = min(res, )
        }
    }
    cout << res;
}
