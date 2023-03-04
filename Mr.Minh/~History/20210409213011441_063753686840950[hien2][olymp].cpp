#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define name "olymp"
#define maxn 1000000

using namespace std;

int n, c, k, a[maxn], res;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin >> n >> c >> k;
    f(i, 1, n) {
        int m, n;               //m la so hang dau, n la cong sai
        cin >> m >> n;
        if (m >= k) a[i] = 0;
        else if (n == 0) a[i] = 1e9;
        else a[i]= (k-m-1)/n + 1;
    }
    sort(a+1, a+n+1);
    //f(i, 1, n) cout << a[i] << ' ';
    while(c >= a[res+1] && res < n){
        res++;
        c-=a[res];
    }
    cout << res;
}
