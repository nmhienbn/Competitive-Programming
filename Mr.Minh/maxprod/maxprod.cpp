#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia ""
//const int maxn = ;
using namespace std;
int a[100002];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    //freopen(Irelia".inp", "r", stdin);
    //freopen(Irelia".out", "w", stdout);
    int n;
    cin >> n;
    fi(i,1,n) {cin >> a[i];}
    sort(a+1,a+n+1);
    cout << max(1ll*a[1]*a[2],1ll*a[n-1]*a[n]);


}
