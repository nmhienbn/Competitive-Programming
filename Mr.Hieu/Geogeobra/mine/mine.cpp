#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define X first
#define Y second
#define pb push_back
#define ll long long
#define Irelia "mine"
using namespace std;

const int maxn = 2e5 + 5;
const double PI = 4 * atan(1);

int n, m, r;
pii a[maxn];
double cv;

bool cmp1(const pii &u , const pii &v) {
    return u.Y == v.Y ? u.X < v.X : u.Y < v.Y;
}
void operator -= (pii& a, pii b){
    a.X -= b.X;
    a.Y -= b.Y;
}
ll ccw(pii c, pii a, pii b){
    a -= c;
    b -= c;
    return 1ll * a.X * b.Y - 1ll * a.Y * b.X;
}

bool cmp(pii u, pii v){
    ll tmp = ccw(a[1], u, v);
    return tmp > 0 || (tmp == 0 && cmp1(u, v));
}

ll sqr(int x) {
    return 1ll * x * x;
}
double dist(const pii &x , const pii &y) {
    return sqrt(sqr(x.X - y.X) + sqr(x.Y - y.Y));
}

void except(){
    if (n == 1) cout << fixed << setprecision(3) << 2 * PI * r, exit(0);
    if (n == 2) cout << fixed << setprecision(3) << dist(a[1], a[2]) * 2 + 2 * PI * r, exit(0);
}

void convexhull(){
    sort(a + 1, a + n + 1, cmp1);
    sort(a + 2, a + n + 1, cmp);
    a[n + 1] = a[1];
    m = 1;
    fi(i, 2, n + 1){
        while (m > 1 && ccw(a[m - 1], a[m], a[i]) <= 0){
            m--;
        }
        a[++m] = a[i];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> r;
    fi(i, 1, n) cin >> a[i].X >> a[i].Y;
    except();
    convexhull();
    m--;
    fi(i, 1, m){
        cv += dist(a[i], a[i + 1]);
    }
    cout << fixed << setprecision(3) << cv + 2 * PI * r << '\n';
}
