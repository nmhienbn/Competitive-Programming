#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pb push_back
#define ll long long
#define Irelia "lcsk"
const int maxn = 1005;
using namespace std;

struct pii {
    int f, s;
};

int n, m, k, f[maxn][maxn], a[maxn], b[maxn], x, y, res;
pii pre[maxn][maxn];
vector<int> A, B;
int q[maxn], d, c;
pii q2[maxn][maxn], g[maxn][maxn];
int d2[maxn], c2[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m >> k;
    fi(i, 1, n) cin >> a[i];
    fi(i, 1, m) cin >> b[i];
    fi(i, 1, m) d2[i] = 1;
    fi(i, 1, n){
        fi(j, 1, m){
            if (a[i] == b[j]){
                f[i][j] = g[q2[d2[j]][j].f][j].f + 1;
                pre[i][j] = q2[d2[j]][j];
            }
            if (f[i][j] > res){
                res = f[i][j];
                x = i;
                y = j;
            }
        }
        d = 1, c = 0;
        q[d] = 0;
        fi(j, 1, m){
            while (q[d] < j - k) d++;
            g[i][j] = {f[i][q[d]], q[d]};
            while (c >= d && f[i][j] >= f[i][q[c]]) c--;
            q[++c] = j;
        }
        fi(j, 1, m){
            while (c2[j] >= d2[j] && g[i][j].f >= g[q2[c2[j]][j].f][j].f) c2[j]--;
            q2[++c2[j]][j] = {i, g[i][j].s};
            while (q2[d2[j]][j].f <= i - k) d2[j]++;
        }
    }
    cout << res << '\n';
    fi(i, 1, res){
        A.pb(x);
        B.pb(y);
        x = pre[A.back()][B.back()].f;
        y = pre[A.back()][B.back()].s;
    }
    for (auto it = A.rbegin(); it != A.rend(); it++) cout << *it << ' ';
    cout << '\n';
    for (auto it = B.rbegin(); it != B.rend(); it++) cout << *it << ' ';
    cout << '\n';
}
