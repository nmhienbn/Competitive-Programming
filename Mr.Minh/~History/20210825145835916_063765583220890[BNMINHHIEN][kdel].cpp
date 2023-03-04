#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "kdel"
const int maxn = 1e5+5, maxa = 1e6+6;

using namespace std;

int n, k, a[maxn], cnt[maxa], now, res;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
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
        res = max(res, cnt[a[i]]);
    }
    cout << res;
}
