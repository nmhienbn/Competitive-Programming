#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL);
#define NunuAndWillump "g"
const int maxn = 1e5+5;

using namespace std;

int n, w, h, a[maxn], b[maxn];

bool check(double k){
    double cnt = 0, now = 0, nowh = 0;
    fi(i, 1, n+1){
        if (k*a[i] > w || k*b[i] > h) return false;
        if (b[i] == b[i-1] && now + k*a[i] <= w && i <= n){
            now += k*a[i];
        }
        else {
            now = k*a[i];
            cnt += nowh;
            nowh = k*b[i];
        }
    }
    return cnt <= h;
}

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n >> w >> h;
    fi(i, 1, n) cin >> a[i] >> b[i];
    double d = 0, c = 1e9;
    while (c-d >= 1e-7){
        double g = (d+c)/2;
        if (check(g)) d = g;
        else c = g;
    }
    cout << fixed << setprecision(6) << c;
}
