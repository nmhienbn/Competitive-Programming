#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "count"
const int maxn = 2005, mod = 1e9 + 7;
using namespace std;

int n, k, res;
int f[maxn][maxn];

void add(int& x, int y){
    x += y;
    if (x >= mod) x -= mod;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> k;
    fi(i, 1, n) f[i][1] = 1;
    fi(j, 1, k - 1){
        fi(i, 1, n){
            for (int t = i; t <= n; t += i){
                add(f[t][j + 1], f[i][j]);
            }
        }
    }
    fi(i, 1, n) add(res, f[i][k]);
    cout << res;
}
