#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define name "bai5"
#define maxn 10005

using namespace std;

int n, a[maxn], p, vt[maxn], check[maxn], dem; // L[i] la so tien neu ks cuoi la i
ll L[maxn];
ll sq(int k){
    return 1ll*k*k;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin >> n >> p;
    f(i, 1, n) cin >> a[i];
    a[0] = 0;
    f(i, 1, n) L[i] = 1e9;
    L[0] = 0; L[1] = sq(a[1] - p);
    f(i, 2, n)
        f(j, 0, i-1)
            if (L[i] > L[j] + sq(a[i] - a[j] - p)){
                L[i] = L[j] + sq(a[i] - a[j] - p);
                vt[i] = j;
            }
    int i = n; check[i] = 1;
    while (i > 0){
        dem++;
        check[vt[i]] = 1;
        i = vt[i];
    }
    cout << L[n] << '\n' << dem << '\n';
    f(i, 1, n) if (check[i]) cout << i << ' ';
}
