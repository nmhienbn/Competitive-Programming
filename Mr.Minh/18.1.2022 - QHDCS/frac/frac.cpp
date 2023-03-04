#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<ll, ll>
#define pb push_back
#define ll long long
#define Irelia "frac"
const int maxn = 35;
using namespace std;

int n;

pii calc(int n){
    if (n == 1) return {1, 1};
    pii tg = calc(n / 2);
    if (n & 1) return {tg.first + tg.second, tg.second};
    return {tg.first, tg.first + tg.second};
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    pii res = calc(n + 1);
    cout << res.first << ' ' << res.second;

}
