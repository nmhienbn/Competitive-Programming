#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "fgift"
const int maxn = 300003;
using namespace std;
int n , m , a[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m ;
    int maxa = 0;
    fi ( i, 1, m) {
        cin >> a[i];
        maxa = max ( maxa, a[i]);
    }
     int d = 1, c = maxa;
    while ( d <= c)
    {
        int g = ( d + c ) /2;
        int t = 0;
        fi ( i, 1, m) t+= ( a[i]-1)/g + 1;
        if ( t <= n) c = g- 1;
        else d = g+ 1;
    }
    cout << d;
}
