#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "prjchain"
const int maxn = 1e5+5;
using namespace std;

struct dl {
    int f, s, id;
    bool operator < (const dl& x) const {
        return f != x.f ? f < x.f : s > x.s;
    }
};

int n, m, cnt;
dl a[maxn], b[maxn], c[maxn];

bool cmp(dl a, dl b){
    return a.s != b.s ? a.s > b.s : a.f < b.f;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> cnt;
    fi(i, 1, cnt) cin >> c[i].f, c[i].id = i;
    fi(i, 1, cnt) cin >> c[i].s;
    fi(i, 1, cnt){
        if (c[i].f <= c[i].s) a[++n] = c[i];
        else b[++m] = c[i];
    }
    sort(a+1, a+n+1);
    sort(b+1, b+m+1, cmp);
    ll res = 0, now = 0;
    fi(i, 1, n){
        now -= a[i].f;
        res = min(res, now);
        now += a[i].s;
    }
    fi(i, 1, m){
        now -= b[i].f;
        res = min(res, now);
        now += b[i].s;
    }
    cout << abs(res) << '\n';
    fi(i, 1, n) cout << a[i].id << ' ';
    fi(i, 1, m) cout << b[i].id << ' ';
}
