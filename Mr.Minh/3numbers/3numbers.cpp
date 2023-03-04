#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "3numbers"
const int maxn = 0;

using namespace std;

int n, a, b;
ll res;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    for (int a = 1; 1ll * a * a * a <= n; a++){
        for (int b = a; 1ll * b * b <= n; b++){
            ll c = n / (a * b);
            if (c < b) continue;
            c = c - b + 1;
            res += c * 6;
            if (a == b){
                res = res - c * 3 - 2;
            }
            else {
                res -= 3;
            }
            //cout << a << ' ' << b << ' ' << res << '\n';
        }
    }
    cout << res;
}
