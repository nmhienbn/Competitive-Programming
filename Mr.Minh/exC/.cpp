#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia ""

using namespace std;

int n, k, d, s;
double res;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
//    freopen(Irelia".inp", "r", stdin);
//    freopen(Irelia".out", "w", stdout);
    cin >> n >> k >> d >> s;
    res = double(n * d - k * s) / (n - k);
    if (res >= 0 && res <= 100){
        cout << fixed << setprecision(6) << res;
    }
    else cout << "impossible";

}
