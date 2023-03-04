#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "pick"
const int maxn = 1005;

using namespace std;

int n, m, a[maxn][maxn], L[maxn][maxn], res = -1e9;

bool kt(int l, int x, int r){
    return l <= x && x <= r;
}

void maximize(int& x, int y){
    if (x < y) x = y;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> m >> n;
    fi(i, 1, m) fi(j, 1, n){
        cin >> a[i][j];
    }
    for (int j = 2; j <= n; j += 2){
        fi(i, 1, m){
            L[i][j] = -1e9;
            fi(u, i - 1, i + 1) fi(v, u - 1, u + 1){
                if (kt(1, u, m) && kt(1, v, m)){
                    maximize(L[i][j], L[v][j - 2] + a[u][j - 1] * a[i][j]);
                }
            }
        }
    }
    fi(i, 1, m) maximize(res, L[i][n]);
    cout << res;
}
