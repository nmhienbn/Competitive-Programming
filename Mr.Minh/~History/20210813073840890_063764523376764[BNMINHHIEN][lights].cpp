#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "lights"
const int maxn = 16;

using namespace std;

int n, k, m, a[5000], b[maxn];
ll dp[5000][1 << 10], L[5000][1 << 10], res = 1e18, maxr;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> k >> m;
    fi(i, 0, n-1){
        cin >> a[i];
    }
    memset(dp, 1, sizeof(dp));
    maxr = dp[0][0];
    fi(x, 0, n-1){
        fi(i, 1, (1 << k) - 1){
            L[x][i] = (i&1)*a[x];
            if (x > 0) L[x][i] += L[x-1][i >> 1];
            if (x == k-1) dp[x][i] = L[x][i];
        }
    }
    fi(x, k, n-1){
        fi(i, 1, (1 << k) - 1){
            int t = (i&(~(1 << (k-1)))) << 1;
            if (L[x][t] >= m) dp[x][t] = min(dp[x][t], dp[x-1][i]);
            if (L[x][t|1] >= m)dp[x][t|1] = min(dp[x][t|1], dp[x-1][i] + a[x]);
            //cout << dp[x][i] << ' ';
        }
        //cout << '\n';
    }
    fi(i, 1, (1 << k) - 1){
        res = min(dp[n-1][i], res);
    }
    if (res == maxr){
        cout << "No solution";
    }
    else cout << res;
}
