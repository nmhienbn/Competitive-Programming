#include <bits/stdc++.h>
#define fi(i,a,b) for(int i=a;i<=b;++i)
#define fid(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define name "cubics"
#define maxn 100005

using namespace std;

int n, k, a[maxn], sum[maxn], vt, res;

//fi(i, 1, n) cin >> arr[i];
//fi(i, 1, n) cout << arr[i] << ' ';


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin >> n >> k;
    fi(i, 1, n) {cin >> a[i]; sum[i] = sum[i-1] + a[i];}
    fid(i, n, 1){
        int d = 1, c = n-i+1;
        while (d <= c){
            int g = (c+d)/2;
            if (sum[g+i-1]-sum[g-1] > k*i) c = g-1;
            else d = g+1;
        }
        if (sum[c+i-1]-sum[c-1] == k*i){
            res = i;
            vt = c;
            break;
        }
    }
    if (res != 0) cout << res << ' ' << vt;
    else cout << 0;
}
