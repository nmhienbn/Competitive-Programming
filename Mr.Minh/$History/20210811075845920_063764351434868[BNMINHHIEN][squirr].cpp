#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "squirr"
const int maxn = 5e4+5;

using namespace std;

int n, m, k, t[maxn], p[maxn];
ll c[maxn];

bool check(ll g){
    ll cnt = 0;
    fi(i, 1, n){
        if (g >= t[i]){
            c[i] = (g-t[i])/p[i]+1;
        }
        else c[i] = 0;
    }
    sort(c+1, c+n+1, greater<ll>());
    fi(i, 1, m) cnt += c[i];
    return cnt >= k;
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> m >> k;
    fi(i, 1, n) cin >> t[i];
    fi(i, 1, n) cin >> p[i];
    ll d = 0, c = k*p[1]+t[1];
    while (d <= c){
        ll g =(d+c) >> 1;
        if (check(g)) c = g-1;
        else d = g+1;
    }
    cout << d;
}
