#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define name "food"
#define maxn 100005

using namespace std;

int m, k, a[maxn], res;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin >> m >> k;
    f(i, 1, m) cin >> a[i];
    int dem = 1;
    f(i, 2, m){
        if (a[i-1] < a[i] && dem < k){ a[i] = a[i-1]; dem++;}
        else dem = 1;
    }
    f(i, 1, m) res += a[i];
    cout << res*2;
}
