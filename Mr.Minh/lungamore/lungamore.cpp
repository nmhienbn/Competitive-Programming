#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "lungamore"
const int maxn = 1e7 + 5;
using namespace std;

int n;
ll len, a[maxn], b[maxn];

void minimize(ll& a, ll b){
    if (a > b) a = b;
}

bool check(ll g){
    ll now = 0;
    fi(i, 1, n){
        if (now + b[i - 1] <= g)
            minimize(now, b[i - 1]);
        now += a[i];
        if (now > g) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> len;
    fi(i, 1, n) cin >> a[i];
    a[n + 1] = len;
    fi(i, 1, n) cin >> b[i];
    n++;
    fid(i, n, 1) a[i] -= a[i - 1];
    ll d = 1, c = 1e18;
    while (d <= c){
        ll g = (d + c) >> 1;
        if (check(g)) c = g - 1;
        else d = g + 1;
    }
    cout << d;
}
