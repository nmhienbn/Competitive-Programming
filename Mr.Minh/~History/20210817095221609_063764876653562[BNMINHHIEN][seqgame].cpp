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
ll a[maxn], b[maxn], c[maxn], d[maxn], e[maxn], f[maxn], res = -1e18;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    fi(i, 1, n){
        a[i] = d[i] = -1e18;
        b[i] = e[i] = 1e18;
    }
    cin >> n;
    cin >> a[1];
    b[1] = a[1];
    fi(i, 2, n){
        ll x;
        cin >> x;
        a[i] = max(a[i-1], x);
        b[i] = min(b[i-1], x);
    }
    fi(i, 1, n){
        cin >> c[i];
    }
    fi(i, 1, n){
        cin >> d[i];
    }
    e[n] = d[n];
    fid(i, n-1, 1){
        d[i] = max(d[i], d[i+1]);
        e[i] = min(e[i], e[i+1]);
    }
    fi(i, 2, n-1){
        res = max({res, a[i-1]*c[i]*d[i+1], b[i-1]*c[i]*e[i+1],
                  a[i-1]*c[i]*e[i+1], b[i-1]*c[i]*d[i+1]});
    }
    cout << res;
}
