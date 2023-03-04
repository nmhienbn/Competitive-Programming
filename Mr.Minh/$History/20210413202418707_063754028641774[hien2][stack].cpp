#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define name "stack"
#define maxn 500005

using namespace std;

int n, a[maxn], top, q[maxn], pre[maxn], nex[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin >> n;
    f(i, 1, n) cin >> a[i];
    top = 0; q[0] = 0; a[0] = -1e9;
    f(i, 1, n){
        while (a[i] <= a[q[top]]) top--;
        pre[i] = q[top] + 1;
        q[++top] = i;
    }
    top = 0; q[0] = n+1; a[n+1] = -1e9;
    fd(i, n, 1){
        while (a[i] <= a[q[top]]) top--;
        nex[i] = q[top] - 1;
        q[++top] = i;
    }
    f(i, 1, n) cout << pre[i] << ' ';
    cout << '\n';
    f(i, 1, n) cout << nex[i] << ' ';
}
