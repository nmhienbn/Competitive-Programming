#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define NunuAndWillump "crate"
const int maxn = 3e5+5;

using namespace std;

struct dl {
    int f, s, id;
    bool operator < (const dl& x) const {
        return f != x.f ? f < x.f : s < x.s;
    }
};

int n, bit[maxn], res[maxn];
dl a[maxn];

void update(int x){
    while (x <= 1e5+1){
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
    fi(i, 1, n) cin >> a[i].f >> a[i].s, a[i].id = i, a[i].f++, a[i].s++;
    sort(a+1, a+n+1);
    fi(i, 1, n){
        if (i > 1 && a[i].f == a[i-1].f && a[i].s == a[i-1].s){
            res[a[i].id] = res[a[i-1].id];
        }
        else res[a[i].id] = get(a[i].s);
        update(a[i].s);
    }
    fi(i, 1, n) cout << res[i] << '\n';
}
