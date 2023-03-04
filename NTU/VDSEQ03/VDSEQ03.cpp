#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "VDSEQ03"
const int maxn = 1e6 + 5;
using namespace std;

int n, a[maxn];
ll sum, val, res;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> val;
    fi(i, 1, n) cin >> a[i];
    int j = 1;
    fi(i, 1, n){
        sum += a[i];
        while (sum - a[j] >= val){
            sum -= a[j++];
        }
        if (sum >= val) res += j;
    }
    cout << res;
}
