#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "tilechng"
const int maxn = 1e4 + 5;
using namespace std;

int n, m, a[15], L[15][maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, n) cin >> a[i];
    memset(L, 60, sizeof L);
    L[0][0] = 0;
    fi(i, 1, n){
        fi(j, 1, m){
            for (int k = 1; k * k <= j; k++){
                L[i][j] = min(L[i][j], L[i - 1][j - k * k]
                              + (a[i] - k) * (a[i] - k));
            }
        }
    }
    cout << (L[n][m] > 1e9 ? -1 : L[n][m]);
}
