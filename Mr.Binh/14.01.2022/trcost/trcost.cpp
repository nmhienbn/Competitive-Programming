#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "trcost"
const int maxn = 1e5 + 5;
using namespace std;

int n, l, res;
ll C;
int a[maxn];
ll s[maxn];

ll calc(int i, int j){
    int x = (i + j) >> 1;
    return s[i - 1] + s[j] - s[x] * 2 + 1ll * (x * 2 - i - j + 1) * a[x];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> l >> C;
    fi(i, 1, n) cin >> a[i], s[i] = s[i - 1] + a[i];
    int j = 1;
    fi(i, 1, n){
        while (calc(j, i) > C) j++;
        res = max(res, i - j + 1);
    }
    cout << res;
}
