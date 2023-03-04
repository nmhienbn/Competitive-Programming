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
ll dp[5000][1 << 10], res = 1e18;

void xuli(){
    int tt = 0;
    ll sum = 0;
    fi(i, 0, k-1){
        tt |= b[i] << (k-1-i);
        sum += a[i]*b[i];
    }
    if (sum >= m){
        dp[k-1][tt] = sum;
    }
}

void ql(int i){
    if (i == k){
        xuli();
        return;
    }
    fi(j, 0, 1){
        b[i] = j;
        ql(i+1);
    }
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> k >> m;
    fi(i, 0, n-1){
        cin >> a[i];
    }
    memset(dp, 1, sizeof(dp));
    //cout << dp[0][0];
    ql(0);
    fi(x, k, n-1){
        fi(i, 1, (1 << k) - 1){
            int t = (i&(~(1 << (k-1)))) << 1;
            ll pre = dp[x-1][i];
            if ((i >> (k-1)) & 1) pre -= a[x-k];
            if (pre >= m) dp[x][t] = min(dp[x][t], dp[x-1][i]);
            if (pre+a[x] >= m)dp[x][t|1] = min(dp[x][t|1], dp[x-1][i] + a[x]);
        }
    }
    fi(i, 1, (1 << k) - 1){
        res = min(dp[n-1][i], res);
    }
    cout << res;
}
