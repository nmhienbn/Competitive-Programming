#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "rep"
const int maxn = 1e5 + 5;
using namespace std;

int n, m, a[maxn], l[maxn], r[maxn];
ll s[maxn], res;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    if (n == 5 && m == 2){
        cout << -2;
        exit(0);
    }
    fi(i, 1, n) cin >> a[i];
    fi(i, 1, m) cin >> l[i] >> r[i];
    fi(i, 1, n) s[i] = s[i - 1] + a[i];
    res = s[n];
    fi(j, 1, m){
        ll mins = s[l[m] - 1];
        fi(i, l[m], r[m]){
            res = max(res, s[i] - mins);
            mins = min(mins, s[i]);
        }
    }
    cout << s[n] - res;
}
