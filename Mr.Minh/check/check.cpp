#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "check"
const int maxn = 2e5+5;
using namespace std;

struct dl {
    char typ;
    int x, y;
    bool operator < (const dl& u) const {
        return x == u.x ? y < u.y : x < u.x;
    }
};

int n, x, y, d, c, vt1, vt2;
dl a[maxn];

void BS(){
    // vt cuoi cung < x
    d = 1, c = n;
    while (d <= c){
        int g = (d + c) >> 1;
        if (a[g].x >= x) c = g-1;
        else d = g+1;
    }
    vt1 = c;

    //vt dau tien > x
    d = 1, c = n;
    while (d <= c){
        int g = (d + c) >> 1;
        if (a[g].x > x) c = g-1;
        else d = g+1;
    }
    vt2 = d;
}

void solve(){
    //1
    fid(i, vt1, 1){
        if (a[i].x - a[i].y == x - y){
            if (a[i].typ != 'R'){
                cout << "YES\n";
                return;
            }
            else break;
        }
    }
    //2
    fid(i, vt1, 1){
        if (a[i].y == y){
            if (a[i].typ != 'B'){
                cout << "YES\n";
                return;
            }
            else break;
        }
    }
    //3
    fid(i, vt1, 1){
        if (a[i].x + a[i].y == x + y){
            if (a[i].typ != 'R'){
                cout << "YES\n";
                return;
            }
            else break;
        }
    }
    //5
    fi(i, vt2, n){
        if (a[i].x - a[i].y == x - y){
            if (a[i].typ != 'R'){
                cout << "YES\n";
                return;
            }
            else break;
        }
    }
    //6
    fi(i, vt2, n){
        if (a[i].y == y){
            if (a[i].typ != 'B'){
                cout << "YES\n";
                return;
            }
            else break;
        }
    }
    //7
    fi(i, vt2, n){
        if (a[i].x + a[i].y == x + y){
            if (a[i].typ != 'R'){
                cout << "YES\n";
                return;
            }
            else break;
        }
    }
    if (vt1+1 >= vt2){
        cout << "NO\n";
        return;
    }
    d = vt1 + 1, c = vt2 - 1;
    while (d <= c){
        int g = (d + c) >> 1;
        if (a[g].y > y) c = g - 1;
        else d = g + 1;
    }
    //8
    fid(i, c, vt1+1){
        if (a[i].typ != 'B'){
            cout << "YES\n";
            return;
        }
        else break;
    }
    //4
    fi(i, d, vt2-1){
        if (a[i].typ != 'B'){
            cout << "YES\n";
            return;
        }
        else break;
    }
    cout << "NO\n";
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    while (cin >> n){
        if (n == -1) break;
        cin >> x >> y;
        fi(i, 1, n) cin >> a[i].typ >> a[i].x >> a[i].y;
        sort(a+1, a+n+1);
        //fi(i, 1, n) cout << a[i].typ << ' ' << a[i].x << ' ' << a[i].y << '\n';
        BS();
        solve();
    }
}
