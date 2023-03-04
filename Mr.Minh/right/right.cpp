#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "right"
const int maxn = 1e5+5;

using namespace std;

int n, d, a[maxn];
ll bit[maxn];

void update(int x, ll val){
    while (x <= 1e5){
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
    cin >> n >> d;
    fi(i, 1, n){
        cin >> a[i];
        ll len = get(a[i]);
        update(a[i], len+d);
        cout << len + d + a[i] << '\n';
    }
}
