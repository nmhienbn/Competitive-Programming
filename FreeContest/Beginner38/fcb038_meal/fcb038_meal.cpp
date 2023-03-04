#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "fcb038_meal"
const int maxn = 1e5 + 5;
using namespace std;

int nt, n, k, a[maxn], cnt[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> nt;
    while (nt--){
        cin >> n >> k;
        fi(i, 1, n) cin >> a[i];
        fi(i, 1, n) cnt[a[i]] = 0;
        int j = 1, res = 0, cur = 0;
        fi(i, 1, n){
            cnt[a[i]]++;
            if (cnt[a[i]] >= cnt[cur]) cur = a[i];
            while (i - j + 1 - cnt[cur] > k && j <= n){
                cnt[a[j]]--;
                j++;
            }
            res = max(res, i - j + 1);
        }
        cout << res << '\n';
    }
}
