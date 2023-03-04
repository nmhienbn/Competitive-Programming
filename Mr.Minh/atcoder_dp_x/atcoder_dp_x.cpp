#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL);
#define NunuAndWillump "atcoder_dp_x"
const int maxn = 1e3+5, maxw = 2e4+5;

using namespace std;

struct dl {
    int u, v, w;
    bool operator < (const dl& x) const {
        return u + v < x.u + x.v;
    }
};

int n;
ll f[maxw];
dl a[maxn];

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        cin >> a[i].u >> a[i].v >> a[i].w;
    }
    sort(a+1, a+n+1);
    fi(i, 1, n){
        fid(j, a[i].v, 0){
            f[j+a[i].u] = max(f[j+a[i].u], f[j] + a[i].w);
        }
    }
    cout << *max_element(f, f+maxw);
}
