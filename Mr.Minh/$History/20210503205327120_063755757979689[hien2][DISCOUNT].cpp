#include <bits/stdc++.h>
#define fi(i,a,b) for(int i=a;i<=b;++i)
#define fid(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define name "DISCOUNT"
#define maxn 100005

using namespace std;

int n, res, a[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i];
    sort (a+1, a+n+1);
    fi(i, 0, (n-1)/3) res += a[3*i+1];
    cout << res;
}
