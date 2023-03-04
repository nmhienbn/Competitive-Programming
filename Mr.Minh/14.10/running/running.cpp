#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "running"
const int maxn = 1e5+5;
using namespace std;

int n, k;
ll t, vtc = 1e18;
pii a[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> t;
    fi(i, 1, n) cin >> a[i].first >> a[i].second;
    k = n;
    fid(i, n, 1){
        ll now = t * a[i].second + a[i].first;
        if (now < vtc){
            vtc = now;
        }
        else {
            k--;
        }
    }
    cout << k;
}
