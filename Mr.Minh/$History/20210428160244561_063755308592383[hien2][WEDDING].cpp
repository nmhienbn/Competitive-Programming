#include <bits/stdc++.h>
#define fi(i,a,b) for(int i=a;i<=b;++i)
#define fid(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define name "WEDDING"
#define maxn 100005

using namespace std;

int n, m, a[maxn], b[maxn], res;

//fi(i, 1, n) cin >> arr[i];
//fi(i, 1, n) cout << arr[i] << ' ';


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin >> n >> m;
    fi(i, 1, n) cin >> a[i];
    sort(a+1, a+n+1);
    fi(i, 1, m) cin >> b[i];
    sort(b+1, b+m+1);
    int i = 1, j = 1, t = 2;
    while (i <= n && t <= m){
        while (b[j] >= a[i] && i <= n) i++;
        while (a[i] >= b[t] && t <= m) t++;
        if (b[j] < a[i] && a[i] < b[t]) i++, j++, t++, res++;
    }
    cout << res;
}
