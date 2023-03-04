#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "fc057_subseq"
const int maxn = 1e5 + 5;
using namespace std;

int n, q, f[maxn], nex[maxn];
unordered_map<ll, int> now;
ll a[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> q;
    fi(i, 1, n) cin >> a[i], now[a[i]] = n + 1;
    fid(i, n, 1){
        f[i] = min(f[i + 1] + 1, now[a[i]] - i);
        now[a[i]] = i;
        int j = i + 1;
        while (f[j] <= f[i] && j <= n){
            j = nex[j];
        }
        nex[i] = j;
    }
    fi(i, 1, q){
        int l, r;
        cin >> l >> r;
        l++;
        r++;
        int res = 0;
        while (l <= r){
            res = max(res, min(r - l + 1, f[l]));
            l = nex[l];
        }
        cout << res << '\n';
    }


}
