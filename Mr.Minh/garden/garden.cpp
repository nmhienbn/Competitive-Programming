#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "garden"
const int maxn = 1e5+5;
using namespace std;

int n, l, a[maxn], b[maxn];

bool check(ll g){
    ll cnt = 0;
    fi(i, 1, n) if (a[i] < g){
        cnt += (g - a[i]) / b[i] + ((g - a[i]) % b[i] > 0);
        if (cnt > l) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> l;
    fi(i, 1, n) cin >> a[i] >> b[i];
    ll d = 0, c = 1e14;
    while (d <= c){
        ll g = (d + c) >> 1;
        if (check(g)) d = g+1;
        else c = g-1;
    }
    cout << c;
}
