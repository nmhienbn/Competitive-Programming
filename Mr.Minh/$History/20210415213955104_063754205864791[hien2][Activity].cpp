#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define name "Activity"
#define maxn 10005
#define maxb 32005

using namespace std;

int n, a[maxn], b[maxn], check[maxn], L[maxb], vt[maxb]; //L[i] la so cuoc hop toi da tu 1 den i gio

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin >> n;
    f(i, 1, n) cin >> a[i] >> b[i];
    L[0] = 0;
    int t = *max_element(b+1, b+n+1);
    f(i, 1, t) L[i] = 0;
    f(i, 1, t)
        f(j, 1, n)
            if (b[j] <= i && L[i] < L[a[j]] + 1){
                L[i] = L[a[j]] + 1;
                vt[i] = j;
            }
    cout << L[t] << '\n';
    int i = t;
    while (i>0){
        i = vt[i];
        check[i] = 1;
    }
    f(i, 1, n) if (check[i]) cout << i << '\n';
}
