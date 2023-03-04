#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "dominating"
const int maxn = 6e5 + 5;
using namespace std;

int n, q, cnt;
int a[maxn];
ll val[maxn];
pair<ll, int> b[maxn];
int f[maxn][20];
vector<int> pos[maxn];

ll solve(){
    int l, r;
    cin >> l >> r;
    int ans = 0;
    fi(i, 0, 19){
        int d1 = f[r][i] - f[l - 1][i];
        int d0 = r - l + 1 - d1;
        if (d1 == d0) return -1;
        if (d1 > d0) ans += 1 << i;
    }
    int lb = lower_bound(pos[ans].begin(), pos[ans].end(), l) - pos[ans].begin();
    int ub = upper_bound(pos[ans].begin(), pos[ans].end(), r) - pos[ans].begin();
    if ((ub - lb) * 2 > r - l + 1) return val[ans];
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> q;
    fi(i, 1, n) cin >> b[i].first, b[i].second = i;
    sort(b + 1, b + n + 1);
    b[0] = {-1, 0};
    fi(i, 1, n){
        if (b[i].first != b[i - 1].first) cnt++, val[cnt] = b[i].first;
        a[b[i].second] = cnt;
        pos[cnt].pb(b[i].second);
    }
    fi(i, 1, n){
        fi(j, 0, 19) f[i][j] = f[i - 1][j] + gb(a[i], j);
    }
    while (q--) cout << solve() << ' ';
}
