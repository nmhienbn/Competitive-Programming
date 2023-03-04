#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia ""
const int maxn = 1505;
using namespace std;

int n;
pii x[maxn];
ll res;
map<int, int> a, b;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> x[i].first >> x[i].second, a[x[i].first]++, b[x[i].second]++;
    fi(i, 1, n){
        res += 1ll * (a[x[i].first] - 1) * (b[x[i].second] - 1);
    }
    cout << res;
}
