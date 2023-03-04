#include <bits/stdc++.h>
#define fi(i, a, b)  for(int i = a, _b = b; i <= _b; i++)
#define fid(i, a, b) for(int i = a, _b = b; i >= _b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "farey"
const int maxn = 4e4 + 5;
const double eps = 1e-7;
using namespace std;

int n, k;
int cnt[maxn];

int calc(double a) {
    cnt[0] = cnt[1] = 0;
    fi(i, 2, n){
        cnt[i] = min(i - 1, int(a * i));
    }
    int res = 0;
    fi(i, 2, n){
        for (int j = 2 * i; j <= n; j += i) {
            cnt[j] -= cnt[i];
        }
        res += cnt[i];
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> k;
    double d = 0, c = 1;
    while (c - d > eps){
        double g = (d + c) / 2;
        if (calc(g) >= k) c = g;
        else d = g;
    }
    fi(i, 1, n){
        if ((c * i - int(c * i)) / i <= eps){
            cout << int(c * i) << ' ' << i;
            exit(0);
        }
    }
}
