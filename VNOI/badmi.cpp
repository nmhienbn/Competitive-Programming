#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "badmi"
const int maxn = 1e5 + 5;
using namespace std;

int n;
ll s[maxn], mins, res = -1e18;
pii a[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        cin >> s[i];
        a[i] = {s[i], i};
        s[i] += s[i - 1];
    }
    sort(a + 1, a + n + 1);
    a[0].first = -1e9 - 1;
    fi(i, 1, n){
        if (a[i].first != a[i - 1].first)
            mins = 1e18;
        res = max(res, s[a[i].second] - mins);
        mins = min(mins, s[a[i].second - 1]);
    }
    cout << res;
}
