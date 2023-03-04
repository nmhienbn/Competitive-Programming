#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "partkx"
const int maxn = 1e4+5, mod = 1e4+7;
using namespace std;

int n, k, x, L[maxn][maxn];

int calc(int n, int k){
    if (k > n || k == 0) return 0;
    if (k == n) return 1;
    if (L[n][k] != -1) return L[n][k];
    return L[n][k] = (calc(n-k, k) + calc(n-1, k-1)) % mod;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> k >> x;
    n -= k*(k-1)/2*x;
    if (n <= 0){
        cout << 0;
        exit(0);
    }
    fi(i, 1, n) fi(j, 1, k) L[i][j] = -1;
    cout << calc(n, k);
}
