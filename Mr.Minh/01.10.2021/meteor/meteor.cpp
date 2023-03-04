#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "meteor"
const int maxn = 1e5+5, maxt = 1e7;

using namespace std;

int n, m, t[maxn];
ll R;

int calc(ll a, ll b, ll c){
    if (c <= 0) return 0;
    ll l = max(- b/a + 1, 1ll), r = 1e7;
    while (l <= r){
        ll m = (l + r) >> 1;
        if (a*m >= 1e18/m || a*m*m + b*m*2 + c >= 0) r = m-1;
        else l = m+1;
    }
    return l;
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> R;
    R = R*R;
    fi(i, 1, n){
        ll x, y, z, vx, vy, vz;
        cin >> x >> y >> z >> vx >> vy >> vz;
        ll a = vx*vx + vy*vy + vz*vz;
        ll b = x*vx + y*vy + z*vz;
        ll c = x*x + y*y + z*z - R*R;
        t[i] = calc(a, b, c);
        cout << t[i] << ' ';
    }
    sort(t+1, t+n+1);
    cin >> m;
    while (m--){
        int tg;
        cin >> tg;
        int d = 1, c = n;
        while (d <= c){
            int g = (d + c) >> 1;
            if (t[g] > tg) c = g-1;
            else d = g+1;
        }
        cout << c << '\n';
    }
}
