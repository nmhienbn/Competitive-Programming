#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "lis"
const int maxn = 2e5+10;

using namespace std;

int a[maxn], n, x, b[maxn], c[maxn],
    bit[maxn], l[maxn], bit2[maxn], res;
vector<int> val;

void update(int x, int len){
    if (!x) return;
    while (x <= n){
        bit[x] = max(bit[x], len);
        x += x & -x;
    }
}

int get(int x){
    int ans = 0;
    while (x > 0){
        ans = max(ans, bit[x]);
        x -= x & -x;
    }
    return ans;
}

void update2(int x, int len){
    while (x > 0){
        bit2[x] = max(bit2[x], len);
        x -= x & -x;
    }
}

int get2(int x){
    int ans = 0;
    if (!x) return 0;
    while (x <= n+5){
        ans = max(ans, bit2[x]);
        x += x & -x;
    }
    return ans;
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> x;
    fi(i, 1, n) cin >> a[i], val.pb(a[i]);
    sort(val.begin(), val.end());
    val.resize(unique(val.begin(), val.end()) - val.begin());
    fi(i, 1, n) b[i] = lower_bound(val.begin(), val.end(), a[i]) - val.begin() + 1;
    fi(i, 1, n) c[i] = lower_bound(val.begin(), val.end(), a[i] - (x-1)) - val.begin() + 1;
    fi(i, 1, n){
        l[i] = get(b[i]-1) + 1;
        update(b[i], l[i]);
    }
    if (x == 0){
        fi(i, 1, n) res = max(res, l[i]);
        cout << res;
        exit(0);
    }
    res = l[n];
    fid(i, n, 1){
        update2(b[i], get2(b[i]+1) + 1);
        if (i > 1) res = max(res, l[i-1] + get2(c[i-1]));
    }
    cout << res;
}
