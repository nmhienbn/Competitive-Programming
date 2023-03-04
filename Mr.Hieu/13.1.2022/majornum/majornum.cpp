#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "majornum"
const int maxn = 1e5 + 5;
using namespace std;

int n, m;
pii a[maxn];
int b[maxn][32];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, n){
        cin >> a[i].first;
        a[i].second = i;
        fi(j, 0, 30) b[i][j] = b[i - 1][j] + gb(a[i].first, j);
    }
    sort(a + 1, a + n + 1);
    fi(i, 1, m){
        int l, r;
        cin >> l >> r;
        int freq = 0, res = 0;
        fi(j, 0, 30){
            freq = b[r][j] - b[l - 1][j];
            if (freq * 2 > r - l + 1) res |= (1 << j);
        }
        int lb = lower_bound(a + 1, a + n + 1, make_pair(res, l)) - a;
        int ub = upper_bound(a + 1, a + n + 1, make_pair(res, r)) - a;
        freq = ub - lb;
        if (freq * 2 > r - l + 1) cout << "1\n";
        else cout << "0\n";
    }
}
