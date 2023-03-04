#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "running"
const int maxn = 1e3+5;
using namespace std;

int n;
ll res, a[maxn];

int bs1(int d, int c, ll k){
    while (d <= c){
        int g = (d + c) >> 1;
        if (a[g] >= k) c = g-1;
        else d = g+1;
    }
    return d;
}

int bs2(int d, int c, ll k){
    while (d <= c){
        int g = (d + c) >> 1;
        if (a[g] <= k) d = g+1;
        else c = g-1;
    }
    return c;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i];
    sort(a+1, a+n+1);
    fi(x, 1, n-2){
        fi(y, x+1, n-1){
            int vt1 = bs1(y+1, n, a[y]*2-a[x]);
            int vt2 = bs2(y+1, n, a[y]*3-a[x]*2);
            if (vt2 >= vt1) res += vt2-vt1+1;
        }
    }
    cout << res;
}
