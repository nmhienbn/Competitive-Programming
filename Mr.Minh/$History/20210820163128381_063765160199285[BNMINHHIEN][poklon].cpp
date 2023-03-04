#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "poklon"
const int maxn = 1e5+5;

using namespace std;

int l, r, n, a[maxn];
ll cd[maxn], cc[maxn], ld[maxn], lc[maxn];

bool kt (ll l, ll a, ll r){
    return l <= a && a <= r;
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> l >> r >> n;
    fi(i, 1, n-1) cin >> a[i];
    a[0] = 2e9, a[n] = 1;
    fi(i, 1, n-1){
        ld[i] = ld[i-1];
        cd[i] = cd[i-1];
        if (i&1) ld[i] += a[i];
        else cd[i] += a[i];
    }
    fid(i, n-1, 1){
        lc[i] = lc[i+1];
        cc[i] = cc[i+1];
        if (i&1) lc[i] += a[i];
        else cc[i] += a[i];
    }
    int pre = 2e9, cnt = 0;
    fi(i, 0, n-1){
        int delta = ld[i] + cc[i+1] - cd[i] - lc[i+1];
        if (i&1){
            if (kt(delta-r, a[i], delta-l)){
                int cc = min(pre, a[i]) - max(delta-r, a[i+1]) + 1;
                if (cc > 0) cnt += cc;
                pre = min(pre, max(delta-r, a[i+1]) - 1);
                //cout << max(delta-r, a[i+1]) << ' ' << a[i] << '\n';
            }
            if (kt(delta-r, a[i+1], delta-l)){
                int cc = min(pre, min(delta-l, a[i])) - a[i+1] + 1;
                if (cc > 0) cnt += cc;
                pre = min(pre, a[i+1] - 1);
                //cout << a[i+1] << ' ' << min(delta-l, a[i]) << '\n';
            }
        }
        else {
            if (kt(l-delta, a[i], r-delta)){
                int cc = min(pre, a[i]) - max(l-delta, a[i+1]) + 1;
                if (cc > 0) cnt += cc;
                pre = min(pre, max(l-delta, a[i+1]) - 1);
                //cout << max(l-delta, a[i+1]) << ' ' << a[i] << '\n';
            }
            if (kt(l-delta, a[i+1], r-delta)){
                int cc = min(pre, min(r-delta, a[i])) - a[i+1] + 1;
                if (cc > 0) cnt += cc;
                pre = min(pre, a[i+1] - 1);
                //cout << a[i+1] << ' ' << min(r-delta, a[i]) << '\n';
            }
        }
    }
    cout << cnt;
}
