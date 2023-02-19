#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "lcs2x"
const int maxn = 1505;
using namespace std;

int nt, m, n, res;
int a[maxn], b[maxn];
int x[maxn], y[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    //freopen(Irelia".inp", "r", stdin);
    //freopen(Irelia".out", "w", stdout);
    cin >> nt;
    while (nt--){
        cin >> m >> n;
        res = 0;
        fi(i, 1, m) x[i] = 0;
        fi(i, 1, n) y[i] = 0;
        fi(i, 1, m) cin >> a[i];
        fi(i, 1, n) cin >> b[i];
        fi(i, 1, m) fi(j, 1, n){
            int tmp = x[i];
            if (b[j] * 2 <= a[i]) x[i] = max(x[i], y[j]);
            if (b[j] == a[i]){
                y[j] = tmp + 1;
                res = max(res, y[j]);
            }
        }
        cout << res << '\n';
    }
}
