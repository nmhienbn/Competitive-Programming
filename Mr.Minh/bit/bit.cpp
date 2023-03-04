#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "bit"
const int maxn = 205;

using namespace std;

int n, k, res, res2;
ll sum;
ll a[maxn];
int cnt[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> k;
    k = min(k, 63);
    fi(i, 1, n){
        cin >> a[i];
        if ((a[i] >> (k - 1)) == 0) a[i] = (1 << k) - 1 - a[i], res++;
        fid(j, k - 1, 0) cnt[j] += ((a[i] >> j) & 1);
        sum += a[i];
    }
    res2 = n - res;
    fi(i, 0, k-1){
        if (cnt[i] * 2 < n){
            res++;
            sum += ((n - cnt[i] * 2) << i);
        }
        else if (cnt[i] * 2 > n){
            res2++;
        }
    }
    cout << min(res, res2) << '\n' << sum;
}
