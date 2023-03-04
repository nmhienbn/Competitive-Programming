#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define name "tien"
#define maxn 105
#define maxm 10005

using namespace std;

int n, m, a[maxn], L[maxm], vt[maxm], dem[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin >> n >> m;
    f(i, 1, n) cin >> a[i];
    f(i, 1, m) L[i] = 1e9;
    L[0] = 0;
    f(i, 1, n) {L[a[i]] = 1; vt[a[i]] = i;}
    f(i, 1, m)
        f(j, 1, n)
            if (a[j] <= i && L[i] > L[i-a[j]] + 1){
                L[i] = L[i-a[j]] +1;
                vt[i] = j;
            }
    if (L[m] == 1e9) {cout << 0; return 0;}
    cout << L[m] << '\n';
    int i = m;
    while (i > 0){
        dem[vt[i]]++;
        i -= a[vt[i]];
    }
    f(i, 1, n) cout << dem[i] << ' ';


}
