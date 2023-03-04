#include <bits/stdc++.h>
#define fi(i,a,b) for(int i=a;i<=b;++i)
#define fid(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define name "bwpoints"
#define maxn 100005

using namespace std;

int n, dem;
pair<int, int> a[maxn], b[maxn], c[2*maxn];

//fi(i, 1, n) cin >> arr[i];
//fi(i, 1, n) cout << arr[i] << ' ';


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin >> n;
    fi(i, 1, n) {cin >> a[i].first; a[i].second = 0;}
    fi(i, 1, n) {cin >> b[i].first; b[i].second = 1;}

    merge(a+1, a+n+1, b+1, b+n+1, c+1);
    fi(i, 2, 2*n){
        if (c[i].second != c[i-1].second) dem++;
    }
    cout << dem;

}
