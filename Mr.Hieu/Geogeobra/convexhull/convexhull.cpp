#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define X first
#define Y second
#define pb push_back
#define ll long long
#define Irelia "convexhull"
const int maxn = 2e5 + 5;
using namespace std;


bool cmp1 (const pii& u, const pii& v){
    return u.Y == v.Y ? u.X < v.X : u.Y < v.Y;
}

void operator -= (pii& u, pii& v){
    u.X -= v.X;
    u.Y -= v.Y;
}

ll CCW(pii C, pii A, pii B){
    A -= C;
    B -= C;
    return 1ll * A.X * B.Y - 1ll *  A.Y * B.X;
}

int n, m;
pii a[maxn];
double cv;
ll dt;

bool cmp2 (const pii& u, const pii& v){
    int tmp = CCW(a[1], u, v);
    return tmp == 0 ? cmp1(u, v) : tmp > 0;
}

void convexHull(){
    sort(a + 1, a + n + 1, cmp1);
    sort(a + 2, a + n + 1, cmp2);
    a[n + 1] = a[1];
    m = 1;
    fi(i, 2, n + 1){
        while (m > 1 && CCW(a[m - 1], a[m], a[i]) <= 0) m--;
        a[++m] = a[i];
    }
    n = m - 1;
}

ll sqr(int x) {
    return 1ll * x * x;
}
double dist(const pii &x , const pii &y) {
    return sqrt(sqr(x.X - y.X) + sqr(x.Y - y.Y));
}

void solve(){
    fi(i, 1, n){
        cv += dist(a[i], a[i + 1]);
        dt += 1ll * (a[i].X - a[i + 1].X) * (a[i].Y + a[i + 1].Y);
    }
    if (dt < 0) dt = -dt;
    cout << n << '\n';
    cout << fixed << setprecision(3) << cv << '\n';
    cout << (dt >> 1) << (dt & 1 ? ".500" : ".000");
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i].X >> a[i].Y;
    convexHull();
    solve();
}
