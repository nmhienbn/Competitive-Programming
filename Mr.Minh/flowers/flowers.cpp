#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "flowers"
const int maxn = 1e5+5;
using namespace std;

bool cmp(pii a, pii b){
    return a.second*b.first > a.first*b.second;
}

int n;
ll t, res;
pii a[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        cin >> a[i].first >> a[i].second;
    }
    sort(a+1, a+n+1, cmp);
    fi(i, 1, n){
        res += t * a[i].second;
        t += a[i].first * 2;
    }
    cout << res;
}
