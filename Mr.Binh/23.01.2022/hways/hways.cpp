#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pdd pair<double, double>
#define pb push_back
#define ll long long
#define Irelia "hways"
const int maxn = 1e5 + 5;
const double PI = acos(-1);
const double eps = 1e-9;
using namespace std;

int n;
double as[maxn];

struct Point {
    double x, y;
    Point () {}
    Point (double x, double y) : x(x), y(y) {}
    Point operator + (Point p) {return Point(x + p.x, y + p.y);}
    Point operator - (Point p) {return Point(x - p.x, y - p.y);}
    double operator * (Point p) {return x * p.y - y * p.x;} //Tich co huong
    bool operator < (const Point& p){
        return x == p.x ? y < p.y : x < p.x;
    }
} a[maxn], b[maxn], p1, p2;

double ch (double x){
    if (x < - PI / 2 + eps) return x + PI * 2;
    return x;
}

double atan(Point p){
    return (ch(atan2(p.y, p.x)));
}

void convex_hull(){
    sort(a + 1, a + n + 1);
    int k = 0;
    fi(i, 1, n){
        while (k > 1 && (b[k] - b[k - 1]) * (a[i] - b[k]) <= 0) k--;
        b[++k] = a[i];
    }
    for (int i = n - 1, t = k; i >= 1; i--){
        while (k > t && (b[k] - b[k - 1]) * (a[i] - b[k]) <= 0) k--;
        b[++k] = a[i];
    }
    n = k - 1;
    fi(i, 1, n) a[i] = b[i];
    a[n + 1] = a[1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    scanf("%d", &n);
    fi(i, 1, n) scanf("%lf%lf", &a[i].x, &a[i].y);
    if (n) convex_hull();
    fi(i, 1, n) as[i] = atan(a[i + 1] - a[i]);
    sort(as + 1, as + n + 1);
    while (~scanf("%lf%lf%lf%lf", &p1.x, &p1.y, &p2.x, &p2.y)){
        if (n < 2){
            puts("GOOD");
            continue;
        }
        int x = upper_bound(as + 1, as + n + 1, atan(p2 - p1)) - as;
        int y = upper_bound(as + 1, as + n + 1, atan(p1 - p2)) - as;
        puts((((p2 - p1) * (a[x] - p1)) * ((p2 - p1) * (a[y] - p1)) > -eps) ? "GOOD" : "BAD");
    }
}
