#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "kperms"
const int maxn = 0;

using namespace std;

int n, k, dp[(1 << 15) + 5][20], res;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> k;
    fi(i, 1, n) dp[1 << (i-1)][i] = 1;
    fi(i, 1, (1 << n) - 1){
        fi(j, 1, n){
            if ((i >> (j-1))&1) fi(t, max(0, j-k), min(n, j+k)){
                dp[i][j] += dp[i^(1 << (j-1))][t];
            }
        }
    }
    fi(i, 1, n){
        res += dp[(1 << n) - 1][i];
    }
    cout << res;
}
