#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define name "PS"
#define maxn 100005

using namespace std;

int n, a[maxn], p[maxn], l=0, r=0, snd=0;
pair<int, int> sum[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin >> n;
    sum[0].first=0;
    sum[0].second=0;
    f(i, 1, n) {
        cin >> a[i];
        sum[i].first=sum[i-1].first+a[i];
        sum[i].second=i;
    }
    sort(sum+1, sum+n+1);
    int minx=sum[1].second, miny=sum[1].second;
    f(i, 2, n){
        if (sum[i].first!=sum[i-1].first){minx=min(minx, sum[i-1].second); miny=minx;}
        else miny=min(miny, sum[i-1].second);
        if (sum[i].second-minx-1 > r-l){
            l=minx+1;
            r=sum[i].second;
        }
        if (sum[i].first!=sum[i+1].first){minx=miny;}
    }

    cout << l << ' ' << r;

}
