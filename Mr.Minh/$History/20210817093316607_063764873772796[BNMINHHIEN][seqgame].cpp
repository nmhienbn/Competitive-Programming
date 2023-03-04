#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "seqgame"
const int maxn = 3e5+5;

using namespace std;

int n;
ll a[maxn], b[maxn], c[maxn], d[maxn], e[maxn];

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) a[i] = b[i] = c[i] = d[i] = e[i] = -1e18;
    fi(i, 1, n){
        ll x;
        cin >> x;
        a[i] = a[i-1];
        b[i] = b[i-1];
        if (x >= 0) a[i] = max(a[i], x);
        else b[i] = max(b[i], -x);
        //cout << a[i] <<  ' ' << b[i] << '\n';
    }
    fi(i, 1, n){
        ll x;
        cin >> x;
        c[i] = c[i-1];
        d[i] = d[i-1];
        if (x >= 0) c[i] = max(c[i], x*a[i-1]), d[i] = max(d[i], x*b[i-1]);
        else c[i] = max(c[i], (-x)*b[i-1]), d[i] = max(d[i], (-x)*a[i-1]);
        //cout << c[i] <<  ' ' << d[i] << '\n';
    }
    fi(i, 1, n){
        ll x;
        cin >> x;
        e[i] = e[i-1];
        if (x >= 0) e[i] = max(e[i], x*c[i-1]);
        else e[i] = max(e[i], (-x)*d[i-1]);
        //cout << e[i] << '\n';
    }
    cout << e[n];
}
