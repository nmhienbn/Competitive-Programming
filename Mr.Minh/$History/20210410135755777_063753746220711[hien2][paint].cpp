#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define name "main"
#define maxn 1000005

using namespace std;

int n, x, res, a[maxn], min_e[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin >> n >>x;
    f(i, 1, n){
        cin >> a[i];
    }
    //f(i, 1, n) cout << i << ' '; cout << endl;
    f(i, 1, n){
        if (i<=n+1-x) min_e[i]=*min_element(a+i, a+x+i);
        else min_e[i]=min_e[n+1-x];
        //cout << min_e[i] << " ";
    }
    //cout <<endl;
    f(i, 1, n){
        res+=a[i]- *max_element(min_e+max(1, i-x+1), min_e+i+1);
        //cout << *max_element(min_e+max(1, i-x+1), min_e+i+1) << ' ';
    }
    //cout << endl;
    //cout << *max_element(min_e+2, min_e+4) << ' ';
    cout <<res;
}
