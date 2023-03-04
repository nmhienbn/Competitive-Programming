#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "ballgame"
const int maxn = 1005;
using namespace std;

int m, n, p, k, c[maxn][15], st[15], en[15];
ll res = 1e18;
char a[maxn][15], b[maxn][15];

void xuli(){
    fi(u, 1, k){
        int j = st[u];
        fi(i, 1, m){
            if (b[i][j] == '\\'){
                if (j < n && b[i][j+1] == '\\') j++;
                else {
                    j = -1;
                    break;
                }
            }
            else {
                if (j > 0 && b[i][j-1] == '/') j--;
                else {
                    j = -1;
                    break;
                }
            }
        }
        if (j != en[u]) return;
    }
    ll ans = 0;
    fi(i, 1, m) fi(j, 1, n) if (a[i][j] != b[i][j]) ans += c[i][j];
    res = min(res, ans);
}

void ql(int i, int j){
    fi(u, 0, 1){
        if (u == 0) b[i][j] = '\\';
        else b[i][j] = '/';
        if (i == m && j == n) xuli();
        else if (j < n) ql(i, j+1);
        else ql(i+1, 1);
    }
}

void sub1(){
    ql(1, 1);
    cout << res;
    exit(0);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> p >> m >> n;
    fi(i, 1, m) fi(j, 1, n) cin >> a[i][j];
    fi(i, 1, m) fi(j, 1, n) cin >> c[i][j];
    cin >> k;
    fi(i, 1, k) cin >> st[i];
    fi(i, 1, k) cin >> en[i];
    if (k == 1 || m * n <= 20){
        sub1();
    }

}
