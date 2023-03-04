#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "c11doll"
const int maxn = 1e5 + 5;
using namespace std;

int n, m, a[maxn], res = -1;
int bit[maxn];

void update(int x, int val){
    while (x > 0){
        bit[x] += val;
        x -= x & -x;
    }
}

int get(int x){
    int ans = 0;
    while (x <= m){
        ans = min(ans, bit[x]);
        x += x & -x;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, n) cin >> a[i];
    fi(i, 1, n / 2){
        update(a[i * 2 - 1] - 1, 1);
        update(a[i * 2] - 1, 1);
        update(a[i] - 1, -1);
        update(a[i], -1);
        if (get(1) >= 0) res = i;
    }
    cout << res;
}
