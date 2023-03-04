#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia ""
const int maxn = 1e5+5;

using namespace std;

int n, a[maxn], ans[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
//    freopen(Irelia".inp", "r", stdin);
//    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    int l = 1, r = n;
    fid(i, n, 1){
        if (i % 2){
            ans[i] = a[r];
            r--;
        }
        else {
            ans[i] = a[l];
            l++;
        }
    }
    fi(i, 1, n) cout << ans[i] << ' ';
}
