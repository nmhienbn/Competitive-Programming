#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define name "PS"
#define maxn 100005

using namespace std;

int n, a[maxn], sum[maxn]={0}, l, r, maxi=0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin >> n;
    sum[0]=0;
    f(i, 1, n) {
        cin >> a[i];
        sum[i]=sum[i-1]+a[i];
    }
    f(i, 1, n)
        f(j, i, n){
            if (sum[j]>sum[i-1] && j-i+1>=maxi){
                l=i; r=j;
                maxi=j-i+1;
            }
        }
    cout << l << ' ' << r;

}
