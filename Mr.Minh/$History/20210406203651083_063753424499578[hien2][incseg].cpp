#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define name "main"
#define maxn 100000

using namespace std;

int n;
int a[maxn];
int maximum;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    f(i, 1, n) cin >> a[i];
    int i=2, dem=1;
    while (i<=n){
        while (a[i]>=a[i-1] && i<=n) {dem++; i++;}
        if (maximum<dem) maximum=dem;
        dem=1;
        i++;
    }
    cout << maximum;

}
