#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL);
#define NunuAndWillump "stack"
const int maxn = 2505, maxw = 2e5+5;

using namespace std;

struct dl {
    int u, v;
    bool operator < (const dl& x) const {
        return u + v < x.u + x.v;
    }
};

int n, res;
map<ll, int> f, h;
dl a[maxn];

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i].u;
    fi(i, 1, n) cin >> a[i].v;
    sort(a+1, a+n+1);
    f[0] = 0;
    fi(i, 1, n){
        for (auto vt : f) if (vt.first <= a[i].v){
            h[vt.first+a[i].u] = max(h[vt.first+a[i].u], vt.second + 1);
        }
        else break;
        f = h;
    }
    for (auto vt : f) res = max(res, vt.second);
    cout << res;
}
