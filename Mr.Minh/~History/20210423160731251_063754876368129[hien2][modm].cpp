#include <bits/stdc++.h>
#define fi(i,a,b) for(int i=a;i<=b;++i)
#define fid(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define name "modm"
#define maxn 100005

using namespace std;

int n, a[maxn], m, b[maxn], dem[maxn], res = 1;

//fi(i, 1, n) cin >> arr[i];
//fi(i, 1, n) cout << arr[i] << ' ';


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin >> n >> m;
    fi(i, 1, n) {
        cin >> a[i];
        a[i] %= m;
        if (a[i] < 0) a[i] += m;
    }
    int i = 1, j = 1;
    while (j <= n){
        dem[a[j]]++;
        if (dem[m-a[j]] > 0 || (a[j] == 0 && dem[a[j]] > 1))
            while ((dem[m-a[j]] > 0 || (a[j] == 0 && dem[a[j]] > 1)) && i <= n)
                dem[a[i++]]--;
        else res = max(res, j-i+1);
        j++;
    }
    cout << res;
}
