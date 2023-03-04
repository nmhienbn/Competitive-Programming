#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "sequence"
const int maxn = 305;
using namespace std;

int n, m, now, pre;
ll a[maxn], f[maxn][maxn];
//thu tu chat k anh huong, chi quan tam vi tri duoc chon

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, n) cin >> a[i], a[i] += a[i - 1];
    fi(k, 1, m){
        fi(i, 1, n){
            fi(j, 0, i - 1){
                f[i][k] = max(f[i][k], f[j][k - 1] + 1ll * a[j] * (a[i] - a[j]));
            }
        }
    }
    cout << f[n][m];
}
