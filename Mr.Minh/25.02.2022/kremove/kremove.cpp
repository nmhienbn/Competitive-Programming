#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "kremove"
const int maxn = 1e6 + 5;
using namespace std;

int n, k, sum, res = 1e9;
int a[maxn];
int q[maxn], d = 1, c;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> k;
    fi(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    fi(i, 1, n - 1) a[i] = a[i + 1] - a[i];
    n--;
    k = n - k;
    fi(i, 1, k - 1){
        sum += a[i];
        while (d <= c && a[q[c]] >= a[i]) c--;
        q[++c] = i;
    }
    fi(i, k, n){
        sum += a[i] - a[i - k];
        while (d <= c && a[q[c]] >= a[i]) c--;
        q[++c] = i;
        while (q[d] <= i - k) d++;
        res = min(res, sum + a[q[d]]);
    }
    cout << res;
}
