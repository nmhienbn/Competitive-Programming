#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "chbh"
const int maxn = 2005;
using namespace std;

ll res, n, m;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, n) fi(j, 1, m){
        res += (i*j+i+j-__gcd(i, j) - 1 + (i-1)*(j-1))*(n-i+1)*(m-j+1);
    }
    cout << res;
}
