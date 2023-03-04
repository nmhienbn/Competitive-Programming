#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "mkuhar"
const int maxn = 105;
using namespace std;

int n, C;
int x[maxn], y[maxn], sm[maxn], sl[maxn], pm[maxn], pl[maxn];

void minimize(int& x, int y){
    if (x > y) x = y;
}

bool check(int g){
    int cnt = 0;
    fi(i, 1, n){
        if (y[i] / x[i] >= g) continue;
        int t = x[i] * g - y[i], ans = 1e9;
        int a, b = 0;
        while (b * sl[i] <= t) {
            a = t - b * sl[i];
            a = a / sm[i] + (a % sm[i] > 0);
            minimize(ans, a * pm[i] + b * pl[i]);
            b++;
        }
        minimize(ans, b * pl[i]);
        cnt += ans;
        if (cnt > C) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> C;
    fi(i, 1, n) cin >> x[i] >> y[i] >> sm[i] >> pm[i] >> sl[i] >> pl[i];
    int d = 1, c = 1e4;
    while (d <= c){
        int g = (d + c) >> 1;
        if (check(g)) d = g + 1;
        else c = g - 1;
    }
    //cout << check(5) << ' ';
    cout << c;
}
