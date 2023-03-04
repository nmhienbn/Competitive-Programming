#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define X first
#define Y second
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL);
#define NunuAndWillump "graham"
const int maxn = 2e5+5;

using namespace std;

pii origin;

void operator -= (pii& a, pii& b){
    a.X -= b.X;
    a.Y -= b.Y;
}

ll ccw(pii w, pii u, pii v){
    u -= w;
    v -= w;
    return 1ll * u.X * v.Y - 1ll * v.X * u.Y;
}

bool cmp(pii u, pii v){
    return ccw(origin, u, v) > 0;
}

int n;
pii a[maxn];

double d(pii u, pii v){
    double x = u.X - v.X;
    double y = u.Y - v.Y;
    return sqrt(x * x + y * y);
}

double S(pii u, pii v, pii w){
    return abs(double(ccw(w, u, v)))/2;
}

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i].X >> a[i].Y;
    sort(a+1, a+n+1);
    origin = a[1];
    sort(a+2, a+n+1, cmp);
    a[n+1] = a[1];
    int j = 1;
    fi(i, 1, n+1){
        while (j > 2 && ccw(a[j-2], a[j-1], a[i]) <= 0) j--;
        a[j++] = a[i];
    }
    n = j-2;
    double P = 0, s = 0;
    fi(i, 1, n){
        P += d(a[i], a[i+1]);
    }
    fi(i, 2, n-1){
        s += S(a[1], a[i], a[i+1]);
    }
    cout << n << '\n' << fixed
        << setprecision(3) << P << '\n' << s << '\n';
}
