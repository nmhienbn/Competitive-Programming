#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL);
#define NunuAndWillump "atcoder_dp_o"
const int maxn = 21, N = 1 << 21, mod = 1e9+7;

using namespace std;

int n, a[maxn][maxn], L[N];

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n;
    fi(i, 0, n-1) fi(j, 0, n-1) cin >> a[i][j];
    int m = (1 << n) - 1;
    L[0] = 1;
    fi(x, 0, m-1){
        int k = __builtin_popcount(x);
        fi(i, 0, n-1){
            if (((x >> i) & 1) == 0 && a[k][i]){
                L[x | (1 << i)] = (L[x | (1 << i)] + L[x]) % mod;
            }
        }
    }
    cout << L[m];

}
