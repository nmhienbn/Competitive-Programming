#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "fibit"
const int maxn = 75;
using namespace std;

int n;
ll f[maxn], d[2][maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    f[1] = f[2] = 1;
    fi(i, 3, 74) f[i] = f[i - 1] + f[i - 2];
    d[0][1] = 0;
    d[1][1] = d[0][2] = d[1][2] = 1;
    fi(i, 3, 74){
        d[1][i] = f[i] + d[1][i - 1] + d[1][i - 2];
    }
}
