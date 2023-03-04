#include <bits/stdc++.h>
#define maxn 200006
#define fi(i,a,b) for(int i=a;i<=b;i++)
#define fid(i,a,b) for(int i=a;i>=b;i--)
#define name "prizes"
#define fir first
#define se second
#define ll long long
#define input(a) scanf("%ld",&a)

using namespace std;
int n, k;
long long res, a[maxn], amax[maxn], ama;

int main(){
    ios_base::sync_with_stdio(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n >> k;
    fi(i, 1, n) {cin >> a[i]; a[i] += a[i-1];}
    fid(i, n - k + 1, 1) amax[i] = max(amax[i+1], a[i+k-1]- a[i-1]);
    ama = 0;
    res = 1e18;
    fi(i, 1, n-k+1) {
        res = min(res, max(ama, amax[i+k]));
        if (i>=k) ama = max(ama, a[i]- a[i-k]);
    }
    cout << res;
}
