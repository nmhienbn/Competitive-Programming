#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "cf_edu1c"
const int maxn = 1e5 + 5;
using namespace std;

struct dl {
    int x, y, id;
};

int n, id = 1, dx = 1e9, dy = 1e9;
dl a[maxn];
double angle = -1e9;

bool ccw(dl a, dl b){
    return (a.x - dx) * (b.y - dy) > (a.y - dy) * (b.x - dx);
}

double an(dl a, dl b){
    return double(a.x * b.x + a.y * b.y) / sqrt(1ll * (a.x * a.x + a.y * a.y) * (b.x * b.x + b.y * b.y));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        cin >> a[i].x >> a[i].y, a[i].id = i;
        if (dy > a[i].y){
            dy = a[i].y;
            dx = a[i].x;
        }
    }
    sort(a + 1, a + n + 1, ccw);
    a[n + 1] = a[1];
    fi(i, 1, n){
        double now = an(a[i], a[i + 1]);
        if (now > angle){
            angle = now;
            id = i;
        }
    }
    cout << a[id].id << ' ' << a[id + 1].id;
}
