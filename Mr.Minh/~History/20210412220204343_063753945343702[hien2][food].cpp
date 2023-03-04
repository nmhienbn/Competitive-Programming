#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define name "food"
#define maxn 100005

using namespace std;

int m, k, a[maxn], d, c, q[maxn], vt;
ll res;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin >> m >> k;
    f(i, 1, m) cin >> a[i];
    d = 1; c = 1; q[1] = 1;
    res = 2*a[1];
    // hang doi
    f(i, 2, m){
        while (a[i] <= a[q[c]] && d <= c) c--;
        q[++c] = i;
        while (i - q[d] + 1 > k) d++;
        res += a[q[d]]*2;
    }
    cout << res;
}
