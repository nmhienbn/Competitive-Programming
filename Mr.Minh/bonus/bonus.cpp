#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "bonus"
const int maxn = 1005, maxm = 1e6 + 5;

using namespace std;

int m, n, q, a[maxn][maxn], b[maxn][maxn];
pii vt[maxm];
int mark[maxm];
int u, l, v, r;

bool check(pii vt){
    return vt.first < u || vt.first > v || vt.second < l || vt.second > r;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> m >> n;
    fi(i, 1, m) fi(j, 1, n){
        cin >> a[i][j];
        if (!vt[a[i][j]].first){
            b[i][j] = 1;
            vt[a[i][j]] = {i, j};
        }
    }
    fi(i, 1, m) fi(j, 1, n){
        b[i][j] += b[i-1][j] + b[i][j-1] - b[i-1][j-1];
    }
    cin >> q;
    fi(test, 1, q){
        cin >> u >> l >> v >> r;
        int res = b[v][r] + b[u-1][l-1] - b[u-1][r] - b[v][l-1];
        fi(i, u, v){
            if (mark[a[i][l]] != test){
                if (check(vt[a[i][l]])) res++;
                mark[a[i][l]] = test;
            }
            if (mark[a[i][r]] != test){
                if (check(vt[a[i][r]])) res++;
                mark[a[i][r]] = test;
            }
        }
        fi(j, l + 1, r - 1){
            if (mark[a[u][j]] != test){
                if (check(vt[a[u][j]])) res++;
                mark[a[u][j]] = test;
            }
            if (mark[a[v][j]] != test){
                if (check(vt[a[v][j]])) res++;
                mark[a[v][j]] = test;
            }
        }
        cout << res << '\n';
    }

}
