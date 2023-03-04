#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "diningb"
const int maxn = 3e4 + 5;
using namespace std;

int n, a[maxn], res = 1e9;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        cin >> a[i];
        a[i] += a[i - 1];
    }
    fi(i, 0, n){
        res = min(res, n * 2 - i * 3 - a[n] + a[i] * 2);
    }
    cout << res;
}
