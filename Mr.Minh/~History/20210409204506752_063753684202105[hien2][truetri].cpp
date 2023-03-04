#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define name "truetri"
#define maxn 100000

using namespace std;

int n, res, a[maxn][2];
map<int, int> x, y;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin >> n;
    f(i, 1, n){
        cin >> a[i][1] >> a[i][2];
        x[a[i][1]]++;
        y[a[i][2]]++;
    }
    f(i, 1, n){
        res+=(x[a[i][1]]-1)*(y[a[i][2]]-1);
    }
    cout << res;
}
