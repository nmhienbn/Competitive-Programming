#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define all(a) a.begin(), a.end()
#define Irelia "pvhlis"
const int maxn = 221000;
using namespace std;

inline void maximize(int& x, int y){
    if (x < y) x = y;
}

int n, a[maxn], N;
int bit[3][maxn * 2], res;
vector<int> val;

void update(int i, int x, int val){
    while (x <= N){
        maximize(bit[i][x], val);
        x += x & -x;
    }
}

int get(int i, int x){
    int ans = 0;
    while (x > 0){
        maximize(ans, bit[i][x]);
        x -= x & -x;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        cin >> a[i];
        val.pb(a[i]);
        val.pb(-a[i]);
    }
    sort(all(val));
    val.resize(unique(all(val)) - val.begin());
    N = val.size();
    fi(i, 1, n){
        int x = lower_bound(all(val), a[i]) - val.begin() + 1;
        int dx = lower_bound(all(val), -a[i]) - val.begin() + 1;
        int L1 = get(0, x - 1) + 1;
        int L2 = max(get(1, dx - 1), get(0, dx - 1)) + 1;
        int L3 = max(get(2, x - 1), get(1, x - 1)) + 1;
        update(0, x, L1);
        update(1, dx, L2);
        update(2, x, L3);
        maximize(res, L3);
        maximize(res, L2);
    }
    cout << res;
}
