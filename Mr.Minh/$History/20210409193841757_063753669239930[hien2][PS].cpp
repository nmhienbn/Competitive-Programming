#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define name "PS"
#define maxn 100005

using namespace std;

int n, a[maxn], p[maxn], l, r, maxi=0, snd=0;
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
    sort(sum, sum+n+1);
    f(i, 1, n)
        f(j, 1, i-maxi){
            if (sum[i].second-sum[j].second>=maxi){
                l=sum[j].second; r=sum[i].second;
                maxi=sum[i].second-sum[j].second;
            }
        }
    cout << l << ' ' << r;

}
