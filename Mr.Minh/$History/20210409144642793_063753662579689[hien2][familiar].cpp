#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define name "familiar"
#define maxn 300005

using namespace std;

int n, res, a[maxn];
bool cmp(int x, int y) {return x > y;}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    f(i, 1, n) {
        cin >> a[i];
    }
    sort(a+1, a+n+1, cmp);
    int maxa=a[1]+1;
    f(i, 1, n) {
        if (a[i]+n >= maxa) res++;
        else break;
        maxa=max(maxa, a[i]+i);
    }
    cout << res;
}
