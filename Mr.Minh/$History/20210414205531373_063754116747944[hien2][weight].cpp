#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define name "weight"
#define maxn 400005

using namespace std;

int n, a[maxn], mina[maxn], maxa[maxn], top, q[maxn], pre[maxn], nex[maxn];
ll res;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin >> n;
    f(i, 1, n) cin >> a[i];

    a[0] = 0; top = 0; q[0] = 0;
    f(i, 1, n){
        while (a[i] >= a[q[top]] && top > 0) top--;
        pre[i] = q[top] + 1;
        q[++top] = i;
    }
    a[n+1] = 0; top = 0; q[0] = n+1;
    fd(i, n, 1){
        while (a[i] >= a[q[top]] && top > 0) top--;
        nex[i] = q[top] - 1;
        q[++top] = i;
    }
    f(i, 1, n) mina[i] = (i - pre[i] + 1) * (nex[i] - i + 1);


    a[0] = 0; top = 0; q[0] = 0;
    f(i, 1, n){
        while (a[i] <= a[q[top]]) top--;
        pre[i] = q[top] + 1;
        q[++top] = i;
    }
    a[n+1] = 0; top = 0; q[0] = n+1;
    fd(i, n, 1){
        while (a[i] <= a[q[top]]) top--;
        nex[i] = q[top] - 1;
        q[++top] = i;
    }
    f(i, 1, n) maxa[i] = (i - pre[i] + 1) * (nex[i] - i + 1);

    f(i, 1, n){
        res += a[i] * (maxa[i] - mina[i]);
    }
    cout << -res;

}
