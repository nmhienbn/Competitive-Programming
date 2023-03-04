#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define ll long long
#define Irelia "vmcandle"
using namespace std;

ll n;
bool flag = 0;

bool check(ll g){
    int t = sqrt(g);
    if (1ll * (t + 1) * (t + 1) <= g) t++;
    return g - t >= n;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    ll d = 1, c = INT64_MAX - 1;
    while (d <= c){
        ll g = (d + c) >> 1;
        if (check(g)) c = g - 1;
        else d = g + 1;
    }
    cout << d;
}
