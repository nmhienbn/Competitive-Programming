#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "trans"
const int maxn = 1005, maxk = 10005, mod = 1e9 + 7;
using namespace std;

int n, k;
int f[maxn][maxk];

void add(int& x, int y){
    x += y;
    if (x >= mod) x -= mod;
}

void sub(int& x, int y){
    x -= y;
    if (x < 0) x += mod;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> k;
    f[0][0] = 1;
    fi(i, 1, n){
        f[i][0] = 1;
        fi(j, 1, k){
            f[i][j] = f[i][j - 1];
            add(f[i][j], f[i - 1][j]);
            if (j >= i) sub(f[i][j], f[i - 1][j - i]);
        }
    }
    cout << f[n][k];
}
