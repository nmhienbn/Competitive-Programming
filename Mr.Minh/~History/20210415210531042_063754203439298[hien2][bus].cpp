#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define name "bus"
#define maxn 105

using namespace std;

int n, m, a[maxn], L[maxn], vt[maxn], check[maxn], dem; //L[i] la tien can trong cach di tm; vt[i] la quang duong di cuoi cung trong cach di tm

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
    f(i, 1, 6) {L[i] = a[i]; vt[i] = i;}
    f(i, 1, m)
        f(j, 1, n)
            if (j <= i && L[i] > L[i - j] + a[j]){
                L[i] = L[i - j] + a[j];
                vt[i] = j;
            }
    cout << L[m] << ' ';
    int i = m;
    while (i > 0){
        dem++;
        check[vt[i]]++;
        i -= vt[i];
    }
    cout << dem << '\n';
    f(i, 1, n) f(j, 1, check[i]) cout << i << ' ';
}
