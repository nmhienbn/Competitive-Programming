#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define NunuAndWillump "mchaos"
const int maxn = 1e5+5;

using namespace std;

struct dl {
    string s;
    int id;
    bool operator < (const dl& x) const {
        return s < x.s;
    }
};

int n, bit[maxn];
ll res;
dl a[maxn];

void update(int x){
    while (x > 0){
        bit[x]++;
        x -= x & -x;
    }
}

int get(int x){
    int ans = 0;
    while (x <= n){
        ans += bit[x];
        x += x & -x;
    }
    return ans;
}

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i].s;
    sort(a+1, a+n+1);
    fi(i, 1, n){
        a[i].id = i;
        reverse(a[i].s.begin(), a[i].s.end());
    }
    sort(a+1, a+n+1);
    fi(i, 2, n){
        update(a[i-1].id);
        res += get(a[i].id+1);
    }
    cout << res;
}
