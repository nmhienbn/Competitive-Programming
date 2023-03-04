#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL);
#define NunuAndWillump "mbus"
const int maxn = 1e5+5;

using namespace std;

struct dl {
    int f, s, t;
};

int x, y, n;
pii b[maxn];
ll bit[maxn], res;
dl a[maxn];

bool cmp(dl a, dl b){
    return a.f != b.f ? a.f < b.f : a.s < b.s;
}

void update(int x, ll val){
    while (x <= n){
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
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> x >> y >> n;
    fi(i, 1, n) cin >> a[i].f >> a[i].s >> a[i].t;
    sort(a+1, a+n+1, cmp);
    fi(i, 1, n) a[i] = {a[i].s, i, a[i].t};
    //fi(i, 1, n) cout << a[i].f << '\n';
    sort(a+1, a+n+1, cmp);
    b[a[1].s].first = 1;
    fi(i, 2, n){
        b[a[i].s].first = b[a[i-1].s].first;
        if (a[i].f != a[i-1].f){
            b[a[i].s].first++;
        }
    }
    fi(i, 1, n) b[a[i].s].second = a[i].t;
    //fi(i, 1, n) cout << b[i].first << ' ' << b[i].second<< '\n';
    fi(i, 1, n){
        ll now = get(b[i].first) + b[i].second;
        //cout << now << '\n';
        res = max(res, now);
        update(b[i].first, now);
    }
    cout << res;
}
