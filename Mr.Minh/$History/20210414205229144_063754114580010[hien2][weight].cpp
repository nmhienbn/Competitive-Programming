#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define name "weight"
#define maxn 400005

using namespace std;

int n, a[maxn], mina, maxa;
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
    f(i, 1, n-1){
        mina = min(a[i], a[i+1]);
        maxa = max(a[i], a[i+1]);
        res += maxa - mina;
        f(j, i+2, n){
            mina = min(mina, a[j]);
            maxa = max(maxa, a[j]);
            res += maxa - mina;
        }
    }
    cout << res;

}
