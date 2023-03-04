#include <bits/stdc++.h>
#define f(i,a,b) for(int i = a;i <= b;++i)
#define fd(i,a,b) for(int i = a;i >= b;--i)
#define ll long long
#define name "PS"
#define maxn 100005

using namespace std;

int n, a[maxn], minS[maxn], S[maxn], vt[maxn], l = 0, r = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen(name".inp","r",stdin);
    //freopen(name".out","w",stdout);
    cin  >>  n;
    S[0] = 0;
    f(i, 1, n) {
        cin  >>  a[i];
        S[i] = S[i-1]+a[i];
        minS[i] = minS[i-1]; vt[i] = vt[i-1];
        if (minS[i] > S[i]){minS[i] = S[i]; vt[i] = i;}
    }
    int j = n-1;
    fd(i, n, 1){
        while(minS[i] < S[i] && j > 0){
            if (r-l+1 <= i-j-1) {
                l = j+2;
                r = i;
            }
            j = vt[j]-1;
        }
    }
    cout  <<  l  <<  ' '  <<  r;

}
