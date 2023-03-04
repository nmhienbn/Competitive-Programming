#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define name "food"
#define maxn 100005

using namespace std;

int m, k, a[maxn], res, d, c, q[maxn], vt;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin >> m >> k;
    f(i, 1, m) cin >> a[i];
    d = 1; c = 0; q[0] = 0; a[0] = -1; vt = 1;
    f(t, 2, m){
        int u = max(1, t-k+1), v = t;

        // hang doi
        f(i, max(vt, u), v){
            while (a[i] <= a[q[c]] && d <= c) c--;
            q[++c] = i;
        }
        while (q[d] < u) d++;
        if (t >= q[d]) a[t] = a[q[d]];
        vt = v+1;
    }
    f(i, 1, m) res += a[i];
    cout << res*2;
}
