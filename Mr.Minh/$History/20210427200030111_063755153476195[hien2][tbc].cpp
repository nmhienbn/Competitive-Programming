#include <bits/stdc++.h>
#define fi(i,a,b) for(int i=a;i<=b;++i)
#define fid(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define name "tbc"
#define maxn 1005

using namespace std;

int n, a[maxn], res;

//fi(i, 1, n) cin >> arr[i];
//fi(i, 1, n) cout << arr[i] << ' ';


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i];
    sort(a+1, a+n+1);
    fi(i, 1, n)
        fi(j, i+1, n)
            fi(k, j+1, n)
                if ((a[i]+a[j]+a[k]) % 3){
                    int *result = find(a+1, a+n+1, (a[i]+a[j]+a[k])/3);
                    if ((result != a+n+1 && result != a+j) && (result != a+i && result != a+k))
                        res++;
                }
    cout << res;
}
