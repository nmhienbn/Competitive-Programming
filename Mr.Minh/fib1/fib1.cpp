#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "fib1"
const int maxn = 50;
using namespace std;

int n, nt, k, f[maxn];

char calc(int n, int k){
    if (k == f[n]){
        if (n) return 'b';
        return 'a';
    }
    if (k > f[n - 2]) return calc(n - 1, k - f[n - 2]);
    return calc(n - 2, k);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    f[0] = f[1] = 1;
    fi(i, 2, 45) f[i] = f[i - 1] + f[i - 2];
    cin >> nt;
    while (nt--){
        cin >> n >> k;
        cout << calc(n, k) << '\n';
    }
}
