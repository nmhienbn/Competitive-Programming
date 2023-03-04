#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "del"
const int maxn = 305;
using namespace std;

int n, a[maxn], f[maxn][maxn];

void minimize(int& x, int y){
    if (x > y) x = y;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i];
    fi(t, 0, n - 1){
        fi(i, 1, n - t){
            int j = i + t;
            f[i][j] = f[i + 1][j] + 1;
            fi(u, i + 1, j) if (a[u] == a[i]){
                minimize(f[i][j], f[i + 1][u - 1] + f[u][j]);
            }
        }
    }
    cout << f[1][n];
}
