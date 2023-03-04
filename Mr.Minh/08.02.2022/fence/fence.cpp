#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "fence"
const int maxn = 1e4 + 5;
const double eps = 1e-4;
using namespace std;

int n, k;
double a[maxn];

bool check(double x){
    if (x < eps) return true;
    ll cnt = 0;
    fi(i, 1, n){
        cnt += (ll)(a[i] / x);
        if (cnt >= k) return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> k;
    fi(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1, greater<double>());
    double d = 0, c = 1e9;
    while (c - d > eps){
        double g = (d + c) / 2;
        if (check(g)) d = g;
        else c = g;
    }
    cout << fixed << setprecision(3) << c;
}
