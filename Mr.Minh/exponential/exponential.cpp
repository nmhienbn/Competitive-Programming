#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL);
#define NunuAndWillump "exponential"
const int maxn = 1e5+5;

using namespace std;

int x, res;

ll mu(ll a, int k){
    if (k == 1) return a;
    ll tg = mu(a, k >> 1);
    if (tg > x) return x+1;
    if (k & 1) return tg * tg * a;
    return tg * tg;
}

int main(){
    faster
    //freopen(NunuAndWillump".inp", "r", stdin);
    //freopen(NunuAndWillump".out", "w", stdout);
    cin >> x;
    fi(i, 2, 17){
        int d = 1, c = x;
        while (d <= c){
            int g = (d + c) >> 1;
            if (mu(g, i) <= x) d = g+1;
            else c = g-1;
        }
        int now = mu(c, i);
        if (now <= x) res = max(res, now);
    }
    cout << res;
}
