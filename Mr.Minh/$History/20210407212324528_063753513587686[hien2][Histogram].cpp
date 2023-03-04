#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define name "Histogram"
#define maxn 20

using namespace std;

int n, a[maxn], kt[maxn], x[maxn], maxi=0, dem=0;

void xuat(){
    int sum=2*n+a[x[1]]+a[x[n]];
    f(i, 1, n-1) sum+=abs(a[x[i]]-a[x[i+1]]);
    if (sum==maxi) dem++;
    if (sum > maxi) {maxi=sum; dem=1;}
}

void backtrack(int i){
    f(j, 1, n) if(!kt[j]){
        kt[j]=1;
        x[i]=j;
        if (i==n) xuat(); else backtrack(i+1);
        kt[j]=0;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    while(cin){
        cin >> n;
        if (n==0) break;
        f(i, 1, n) cin >> a[i];
        maxi=0, dem=0;
        backtrack(1);
        cout << maxi << ' ' << dem << '\n';
    }



}
