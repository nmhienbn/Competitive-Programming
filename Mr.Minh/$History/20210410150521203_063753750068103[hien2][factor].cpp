#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define name "factor"
#define maxn 100005
#define maxa 10000005

using namespace std;

int n, a[maxn], b[30];
int nto[maxa + 5]; // ham uoc nguyen to lon nhat

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin >> n;
    f(i, 1, n) cin >> a[i];
    nto[1] = 1;
    f(i, 2, sqrt(maxa))
        if (nto[i] == 0){
            nto[i] = i;
            for (int j = i*i; j <= maxa; j += i) nto[j] = i;
        }

    f(i, 1, n){
        int sl=0;
        while (a[i] > 1){
            b[++sl] = nto[a[i]];
            a[i] /= nto[a[i]];
        }
        sort(b+1, b+sl+1);
        cout << b[1];
        f(t, 2, sl) cout << '*' << b[t];
        cout << '\n';
    }
}
