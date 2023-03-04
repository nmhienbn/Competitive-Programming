#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define all(a) a.begin(), a.end()
#define pb push_back
#define ll long long
#define Irelia "qbsegpar"
const int maxn = 15005;
using namespace std;

int n, k, a[maxn];
vector<int> val;
int bit1[maxn], bit2[maxn];

void ud1(int x, int val){
    while (x > 0){
        bit1[x] = min(bit1[x], val);
        x -= x & -x;
    }
}

int get1(int x){
    int ans = 1e9;
    while (x < maxn){
        ans = min(ans, bit1[x]);
        x += x & -x;
    }
    return ans;
}

void ud2(int x, int val){
    while (x > 0){
        bit2[x] = max(bit2[x], val);
        x -= x & -x;
    }
}

int get2(int x){
    int ans = -1e9;
    while (x < maxn){
        ans = max(ans, bit2[x]);
        x += x & -x;
    }
    return ans;
}

bool check(int m){
    fi(i, 1, maxn - 1){
        bit1[i] = 1e9;
        bit2[i] = -1e9;
    }
    int mi, ma;
    int now = lower_bound(all(val), 0) - val.begin() + 1;
    ud1(now, 0);
    ud2(now, 0);
    fi(i, 1, n){
        int pre = lower_bound(all(val), a[i] - m) - val.begin() + 1;
        mi = get1(pre) + 1;
        ma = get2(pre) + 1;
        int now = lower_bound(all(val), a[i]) - val.begin() + 1;
        ud1(now, mi);
        ud2(now, ma);
    }
    return mi <= k && k <= ma;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> k;
    val.resize(n + 1);
    val[0] = 0;
    fi(i, 1, n){
        cin >> a[i];
        a[i] += a[i - 1];
        val[i] = a[i];
    }
    sort(all(val));
    val.resize(unique(all(val)) - val.begin());
    int d = -1e9, c = 1e9;
    while (d <= c){
        int g = (d + c) >> 1;
        if (check(g)) c = g - 1;
        else d = g + 1;
    }
    cout << d;
}
