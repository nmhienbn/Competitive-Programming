#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL);
#define NunuAndWillump "area"
const int maxn = 3e4+5;

using namespace std;

struct dl {
    int a, b, c, typ;
    bool operator < (const dl& x) const {
        return a != x.a ? a < x.a : typ < x.typ;
    }
};

struct IT{
    int len, cnt;
};

int n, ans, m;
dl a[maxn];
IT st[maxn << 2];

void update(int id, int l, int r, int d, int c, int typ){
    if (r < d || l > c || c < d) return;
    if (d <= l && r <= c){
        st[id].cnt += typ;
        if (typ == 1) st[id].len = r-l+1;
        else if (st[id].cnt == 0){
            if (l < r) st[id].len = st[id*2].len + st[id*2+1].len;
            else st[id].len = 0;
        }
        return;
    }
    int m = (l+r) >> 1;
    update(id*2, l, m, d, c, typ);
    update(id*2+1, m+1, r, d, c, typ);
    if (st[id].cnt == 0 && l < r){
        st[id].len = st[id*2].len + st[id*2+1].len;
    }
}

int main(){
    faster
//    freopen(NunuAndWillump".inp", "r", stdin);
//    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a[i] = {x1, y1+1, y2, 1};
        a[i+n] = {x2, y1+1, y2, -1};
        m = max(m, y2);
    }
    n += n;
    sort(a+1, a+n+1);
    fi(i, 1, n){
        ans += st[1].len * (a[i].a - a[i-1].a);
        update(1, 1, m, a[i].b, a[i].c, a[i].typ);
    }
    cout << ans;
}
