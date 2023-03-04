#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "partition"
const int maxn = 50005;
using namespace std;

int n, w, h, num;
bool flag;

struct point {
    int x, y;
    bool below;
    void read(){
        cin >> x >> y;
        x = x * 2 - w;
        y = y * 2 - h;
        if (y < 0 || (y == 0 && x < 0)){
            x = -x;
            y = -y;
            below = 1;
            num++;
        }
    }
    bool operator < (const point& p) const{
        return x * p.y > y * p.x;
    }
} a[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> w >> h;
    fi(i, 1, n) a[i].read();
    sort(a + 1, a + n + 1);
    int offset = 1;
    for (; num * 2 != n; offset++){
        if (a[offset].below) num--;
        else num++;
    }
    cout << a[offset].y << ' ' << -a[offset].x << ' ' << (a[offset].x * h - w * a[offset].y) / 2;
}
