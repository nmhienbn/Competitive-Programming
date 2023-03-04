#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "atcoder_dp_q"
const int maxn = 2e5+5;

using namespace std;

int n;
ll bit[maxn], res;
pii a[maxn];

void update(int x, ll val){
    while (x <= n){
        bit[x] = max(bit[x], val);
        x += x & -x;
    }
}

ll get(int x){
    ll ans = 0;
    while (x > 0){
        ans = max(ans, bit[x]);
        x -= x & -x;
    }
    return ans;
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i].first;
    fi(i, 1, n) cin >> a[i].second;
    fi(i, 1, n){
        ll l = get(a[i].first-1) + a[i].second;
        update(a[i].first, l);
        res = max(res, l);
    }
    cout << res;
}
