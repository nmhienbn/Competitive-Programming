#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define name "factor"
#define maxn 100005

using namespace std;

int n, a[maxn], maxa;
bool check[maxn]={0}; // =0 la snt

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin >> n;
    f(i, 1, n) cin >> a[i];
    maxa = *max_element(a+1, a+n+1);
    check[1] = 1;
    f(i, 2, sqrt(maxa))
        for (int j = i*i; j <= maxa; j += i) check[j]=1;
    f(i, 1, n){
        f(j, 2, a[i])
            while (!check[j] && a[i]%j == 0){
                if (a[i]==j) cout << j;
                else cout << j << '*';
                a[i]/=j;
            }
        cout << '\n';
    }
}
