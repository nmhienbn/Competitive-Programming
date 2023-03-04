#include <bits/stdc++.h>
#define fi(i,a,b) for(int i=a;i<=b;++i)
#define fid(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define name "linegame"
#define maxn 1000005

using namespace std;

int n, a[maxn], cong, tru;
//tru la lay max den tinh den a[i], co a[i] va la -a[i]
//cong la lay max den tinh den a[i], co a[i] va la +a[i]

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i];
    fi(i, 1, n){
        int tg1 = cong - a[i];
        int tg2 = tru + a[i];
            cong = max(cong, tg2);
            tru = max(tru, tg1);
        }
    cout << max(cong, tru);
}
