#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define NunuAndWillump "nkmaxseq"
const int maxn = 5e4+5;

using namespace std;

int n, p, bit[maxn], a[maxn], res;
vector<int> b;

void update (int x, int val){
    while (x > 0){
        bit[x] = min(bit[x], val);
        x -= x & -x;
    }
}

int get(int x){
    int ans = 1e9;
    while (x <= n+4){
        ans = min(ans, bit[x]);
        x += x & -x;
    }
    return ans;
}

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n >> p;
    b.pb(0);
    fi(i, 1, n) cin >> a[i], a[i] += a[i-1], b.pb(a[i]);//, cout << a[i] << ' ';
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    fi(i, 0, n+4) bit[i] = 1e9;
    fi(i, 1, n){
        int now = lower_bound(b.begin(), b.end(), a[i-1]) - b.begin() + 1;
        update(now, i-1);
        int pre = lower_bound(b.begin(), b.end(), a[i]-p) - b.begin() + 1;
        res = max(res, i-get(pre)-1);
        //cout << pre << ' ';
    }
    cout << res;
}
