#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define name "frogs"
#define maxn 1000005

using namespace std;

int n, a[maxn], b[maxn], top, q[maxn], nex[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin >> n;
    f(i, 1, n) cin >> a[i];
    a[n+1] = -1;
    f(i, 1, n) cin >> b[i];
    top = 0; q[0] = n;
    fd(i, n-1, 1){
        while (a[i] > a[q[top]]) top--;
        nex[i] = q[top];
        q[++top] = i;
    }
    nex[n] = n+1;
    f(i, 1, n-1){
        int res = nex[i];
        while (b[i] > 1 && res < n+1){
            res = nex[res];
            b[i]--;
        }
        cout << a[res] << ' ';
    }
    cout << -1;
}
