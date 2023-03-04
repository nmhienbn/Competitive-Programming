#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define name "SOCOLATE"
#define maxn 100005

using namespace std;

int n;
ll b, res;
pair<ll, ll> a[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen(name".inp","r",stdin);
    //freopen(name".out","w",stdout);
    cin >> n >> b;
    f(i, 1, n) cin >> a[i].first >> a[i].second;
    sort(a+1, a+n+1);
    f(i, 1, n){
        if (b/a[i].first >= a[i].second){
            res+=a[i].second;
            b-=a[i].first*a[i].second;
        }
        else {res +=b/a[i].first; break;}
    }
    cout <<res;



}
