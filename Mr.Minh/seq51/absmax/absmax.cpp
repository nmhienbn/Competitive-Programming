#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "absmax"
const int maxn = 2e5 + 5;
using namespace std;

int n, mina, maxa, x, res;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> x;
    n--;
    mina = maxa = x;
    while (n--){
        cin >> x;
        res = max({res, abs(x + maxa), abs(x + mina)});
        maxa = max(maxa, x);
        mina = min(mina, x);
    }
    cout << res;
}
