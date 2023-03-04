#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "game1"
const int maxn = 705;
using namespace std;

int n, f[maxn][maxn], a[maxn];

int calc(int l, int r){
    if (l >= r - 1) return 0;
    if (f[l][r]) return f[l][r];
    int& w = f[l][r];
    fi(i, l + 1, r - 1){
        w = max(w, calc(l, i) + a[i] * (a[l] + a[r]) + calc(i, r));
    }
    return w;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i];
    cout << calc(1, n);
}
