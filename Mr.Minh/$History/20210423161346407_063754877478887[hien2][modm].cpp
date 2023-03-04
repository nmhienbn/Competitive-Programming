#include <bits/stdc++.h>
#define fi(i,a,b) for(int i=a;i<=b;++i)
#define fid(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define name "modm"
#define maxn 100005

using namespace std;

int n, a[maxn], m, dem[maxn], res = 1;

//fi(i, 1, n) cin >> arr[i];
//fi(i, 1, n) cout << arr[i] << ' ';


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin >> n >> m;
    fi(i, 1, n){
        cin >> a[i];
        a[i] %= m;
        if (a[i] < 0) a[i] += m;
        dem[a[i]]++;
    }
    res = min(dem[0], 1);
    if (m%2 == 0) res += min(dem[a[m/2]], 1);
    fi(i, 1, (m-1)/2) res += max(dem[i], dem[m-i]);
    cout << res;
}
