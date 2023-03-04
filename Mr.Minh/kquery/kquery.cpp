#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define NunuAndWillump "kquery"
const int maxn = 3e4+5, maxq = 2e5+5;

using namespace std;

struct dl{
    int i, j, k, id;
    bool operator < (const dl& x) const {
        return k > x.k;
    }
} b[maxq];

int n, q, res[maxq], bit[maxn];
pii a[maxn];

void update(int x){
    while (x <= n){
        bit[x]++;
        x += x & -x;
    }
}

int get(int x){
    int ans = 0;
    while (x > 0){
        ans += bit[x];
        x -= x & -x;
    }
    return ans;
}

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i].first, a[i].second = i;
    sort(a+1, a+n+1, greater<pii>());
    cin >> q;
    fi(i, 1, q) cin >> b[i].i >> b[i].j >> b[i].k, b[i].id = i;
    sort(b+1, b+q+1);
    int j = 1;
    fi(i, 1, q){
        int k = b[i].k;
        while (a[j].first > k && j <= n) update(a[j].second), j++;
        res[b[i].id] = get(b[i].j) - get(b[i].i-1);
    }
    fi(i, 1, q) cout << res[i] << '\n';
}
