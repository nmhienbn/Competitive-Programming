#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "prizes"
const int maxn = 1e5+5;

using namespace std;

int n, k;
ll a[maxn], maxL, maxR[maxn], res = 1e18;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> k;
    fi(i, 1, n){
        cin >> a[i];
        a[i] += a[i-1];
    }
    fid(i, n-k+1, 1){
        maxR[i] = max(maxR[i+1], a[i+k-1] - a[i-1]);
    }
    fi(i, 1, n-k+1){
        res = min(res, max(maxL, maxR[i+k]));
        if (i >= k) maxL = max(maxL, a[i] - a[i-k]);
    }
    cout << res;
}
