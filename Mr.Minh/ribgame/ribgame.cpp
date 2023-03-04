#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "ribgame"
const int maxn = 2e5+5;
using namespace std;

int n, m, res, a[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, n){
        int l, r, s;
        cin >> l >> r >> s;
        a[l] += s;
        a[r+1] -= s;
        res += s;
    }
    fi(i, 1, m) a[i] += a[i-1];
    cout << res - *min_element(a+1, a+m+1);
}
