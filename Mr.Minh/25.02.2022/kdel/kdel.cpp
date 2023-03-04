#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "kdel"
const int maxn = 1e5 + 5;
using namespace std;

int n, k, now, res;
int a[maxn];
unordered_map<int, int> cnt;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> k;
    fi(i, 1, n) cin >> a[i];
    int j = 1;
    fi(i, 1, n){
        cnt[a[i]]++;
        if (cnt[a[i]] == 1) now++;
        while (now > k+1){
            cnt[a[j]]--;
            if (cnt[a[j]] == 0) now--;
            j++;
        }
        if (res < cnt[a[i]]) res = cnt[a[i]];
    }
    cout << res;

}
