#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define maxn 1000000000
#define maxm 300005

using namespace std;

int n, m, a[maxm], res=-maxn, sum;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    int maxa=-maxn;
    f(i, 1 , m) {cin >> a[i]; maxa=max(maxa, a[i]);}
    f(i, 1, maxa){
        sum=0;
        f(j, 1, m) sum+=(a[j]-1)/i + 1;
        if (sum <= n) {res=max(res, i); break;}
    }
    cout << res;
}
