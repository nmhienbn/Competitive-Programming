#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "carshow1"
const int maxn = 1e5+5;
using namespace std;

int n, t, a[maxn], b[maxn], res;
ll nex = 1e18 + 1e9;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> t;
    fi(i, 1, n) cin >> a[i] >> b[i];
    res = n;
    fid(i, n, 1){
        ll now = 1ll*t*b[i] + a[i];
        if (now >= nex) res--;
        else nex = now;
    }
    cout << res;
}
#include <bits/stdc++.h>
#define f(i,a,b) for (int i=a;i<=b;i++)
#define int long long
#define pii pair<int,int>
#define piii pair<int , pii>
#define F first
#define S second
#define task "cardrag"
#define mod 65536
#define endl '\n'
#define Y "YES\n"
#define N "NO\n"
using namespace std;
const int maxn = 2001;

int n,m,k;
int nex[4][maxn];
char a[maxn][maxn];
int32_t main() {
    ios_base::sync_with_stdio(false);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin.tie(0);
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        f(i,1,n) f(j,1,m) cin >> a[i][j];
        int ans = 0;
        f(i,1,m) {
            nex[0][i] = 1;
            nex[2][i] = n;
        }
        f(i,1,n) {
            nex[1][i] = m;
            nex[3][i] = 1;
        }
        int check = 1;
        while (check) {
            check = 0;
            f(i,1,m) {
                while (nex[0][i] <= n && (a[nex[0][i]][i] == '.' || a[nex[0][i]][i] == 'N')) {
                    if (a[nex[0][i]][i] == 'N') {
                        a[nex[0][i]][i] = '.';
                        ans ++;
                        check = 1;
                    }
                    nex[0][i] ++ ;

                }
            }
            f(i,1,n) {
                while (nex[1][i] >= 1 && (a[i][nex[1][i]] == '.' || a[i][nex[1][i]] == 'E')) {
                    if (a[i][nex[1][i]] == 'E') {
                        a[i][nex[1][i]] = '.';
                        ans ++;
                        check = 1;

                    }
                    nex[1][i]--;
                }
            }
            f(i,1,m) {
                while (nex[2][i] >= 1 && (a[nex[2][i]][i] == '.' || a[nex[2][i]][i] == 'S')) {
                    if (a[nex[2][i]][i] == 'S') {
                        a[nex[2][i]][i] = '.';
                        ans ++;
                        check = 1;
                    }
                    nex[2][i] -- ;

                }
            }
            f(i,1,n) {
                while (nex[3][i] <= m && (a[i][nex[3][i]] == '.' || a[i][nex[3][i]] == 'W')) {
                    if (a[i][nex[3][i]] == 'W') {
                        a[i][nex[3][i]] = '.';
                        ans ++;
                        check = 1;

                    }
                    nex[3][i]++;
                }
            }
        }
        cout << ans << '\n';
    }

}
1
