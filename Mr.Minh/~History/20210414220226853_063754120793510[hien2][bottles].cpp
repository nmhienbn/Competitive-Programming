#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define name "bottles"
#define maxn 400005

using namespace std;

int n, k, a[maxn], L[maxn], q[maxn], vt[maxn], xd[maxn],d, c, S, dem;
ll res;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin >> n >> k;
    f(i, 1, n) {cin >> a[i]; S += a[i];}
    L[0] = 0; q[0] = 0; d = 0; c = 0; a[n+1] = 0;
    f(i, 1, n+1){
        while (q[d] < i-k) d++;
        L[i] = L[q[d]] + a[i];
        vt[i] = q[d];
        while (L[i] <= L[q[c]] && d <= c) c--;
        q[++c] = i;
    }
    res = S - L[n+1];
    int i = n+1; xd[i] = 1;
    while (i > 0){
        dem++;
        i = vt[i];
        xd[i] = 1;
    }
    cout << n-dem+1 << ' ' << res << '\n';
    f(i, 1, n) if (!xd[i]) cout << i << ' ';
}
