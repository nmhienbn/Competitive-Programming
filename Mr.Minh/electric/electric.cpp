#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "electric"
const int maxn = 2e5 + 5, maxk = 1e6 + 5;
using namespace std;

int n, m, k, mod, res, ans;
pii a[maxk];
int bit[maxn];

bool cmp(pii a, pii b){
    return a.first == b.first ? a.second > b.second : a.first < b.first;
}

void update(int x, int val){
    while (x <= m){
        (bit[x] += val) %= mod;
        x += x & -x;
    }
}

int get(int x){
    int ans = 0;
    while (x > 0){
        (ans += bit[x]) %= mod;
        x -= x & -x;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m >> k >> mod;
    fi(i, 1, k) cin >> a[i].first >> a[i].second;
    sort(a + 1, a + k + 1, cmp);
    fi(i, 1, k){
        ans = get(a[i].second - 1) + 1;
        update(a[i].second, ans);
        (res += ans) %= mod;
    }
    cout << (res + 1) % mod;
}
