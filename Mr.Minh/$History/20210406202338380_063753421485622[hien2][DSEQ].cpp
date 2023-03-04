#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define name "main"
#define maxn 100000

using namespace std;

int n, dem;
int a[maxn];
long long maximum;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    f(i, 1, n) cin >> a[i];
    long long tong[maxn];
    tong[0]=0;
    for (int i=1; i <= n; i++){tong[i]=tong[i-1]+a[i];}
    maximum=abs(a[1]-a[n]);
    f(i, 1, n-1){
        f(j, i+1, n){
            int m=abs(tong[i]-tong[n]+tong[j-1]);
            if (m >= maximum){
                if (m==maximum) dem++;
                else dem=1;
                maximum=m;
            }
        }
    }
    cout << maximum << " " <<dem;
}
