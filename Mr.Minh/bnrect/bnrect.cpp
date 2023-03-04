#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "bnrect"
const int maxn = 1e6+5;

using namespace std;

int n, b[maxn], k;
pii a[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        cin >> a[i].first >> a[i].second;
        if (a[i].first > a[i].second) swap(a[i].first, a[i].second);
    }
    sort(a + 1, a + n + 1);
    fi(i, 1, n){
        int d = upper_bound(b+1, b+k+1, a[i].second) - b;
        if (d == k + 1) b[++k] = 1e9;
        b[d] = min(b[d], a[i].second);
    }
    cout << k;
}
