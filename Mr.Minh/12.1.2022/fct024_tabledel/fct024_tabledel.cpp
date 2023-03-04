#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define rep(i, b) for(int i = 0, _b = (b); i < _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "fct024_tabledel"
const int maxn = 1e5 + 5;
using namespace std;

int n, m, k, a[maxn], b[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m >> k;
    rep(i, k) cin >> a[i] >> b[i];
    sort(a, a + k);
    sort(b, b + k);
    n = unique(a, a + k) - a;
    m = unique(b, b + k) - b;
    cout << m * n;

}
