#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "saw"
const int maxn = 1e5+5;

using namespace std;

ll n, m, a[maxn];
ll s[maxn];

ll bs(ll x){
    ll d = 1, c = n;
    while (d <= c){
        ll g = (d+c) >> 1;
        if (a[g] >= x) c = g-1;
        else d = g+1;
    }
    return c;
}

ll calc(ll g){
    ll t = bs(g);
    //cout << g << ' ' << s[n] - s[t] - g*(n-t) << '\n';
    return s[n] - s[t] - g*(n-t);
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, n) cin >> a[i];
    sort(a+1, a+n+1);
    fi(i, 1, n) s[i] = s[i-1] + a[i];
    while (m--){
        ll k;
        cin >> k;
        ll d = 0, c = a[n];
        while (d <= c){
            ll g = (d+c) >> 1;
            if (calc(g) < k) c = g-1;
            else d = g+1;
        }
        cout << c << ' ';
    }
}
