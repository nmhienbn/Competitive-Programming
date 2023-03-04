#include <bits/stdc++.h>
#define fi(i,a,b) for(int i=a;i<=b;++i)
#define fid(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define name "APPLICATION"
#define maxn 100005

using namespace std;

int n, a[maxn], d, c, g;
ll m, hs;

//fi(i, 1, n) cin >> arr[i];
//fi(i, 1, n) cout << arr[i] << ' ';


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin >> n >> m;
    fi(i, 1, n) cin >> a[i];
    d = 1; c = 1e9;
    while (d < c){
        g = (c+d)/2;
        hs = 0;
        fi(i, 1, n) hs += g/a[i];
        if (hs >= m) c = g-1;
        else d = g+1;
    }
    cout << c;
}
