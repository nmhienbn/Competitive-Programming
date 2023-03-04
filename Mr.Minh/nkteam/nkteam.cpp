#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define NunuAndWillump "nkteam"
const int maxn = 1e5+5;

using namespace std;

struct dl {
    int a, b, c;
    bool operator < (const dl& x) const {
        return a < x.a;
    }
} a[maxn];

int n, bit[maxn], cnt;

void update(int x, int val){
    while (x <= n){
        bit[x] = min(bit[x], val);
        x += x & -x;
    }
}

int get(int x){
    int ans = 1e9;
    while (x > 0){
        ans = min(ans, bit[x]);
        x -= x & -x;
    }
    return ans;
}

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    memset(bit, 60, sizeof(bit));
    cin >> n;
    int x;
    fi(i, 1, n) cin >> x, a[x].a = i;
    fi(i, 1, n) cin >> x, a[x].b = i;
    fi(i, 1, n) cin >> x, a[x].c = i;
    sort(a+1, a+n+1);
    fi(i, 1, n){
        cnt += get(a[i].b) >= a[i].c;
        update(a[i].b, a[i].c);
    }
    cout << cnt;
}
