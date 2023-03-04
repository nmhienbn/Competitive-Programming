#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "lock"
const int maxn = 1e5 + 10;
using namespace std;

int n, m, a[11];
int cost[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int dp[maxn], trace[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, m) cin >> a[i];
    fi(i, 1, n){
        dp[i] = -1e9;
        fid(j, m, 1){
            if (a[j] == 0 && i == n && n != cost[0]) continue;
            if (i >= cost[a[j]] && dp[i] < dp[i - cost[a[j]]] + 1){
                dp[i] = dp[i - cost[a[j]]] + 1;
                trace[i] = a[j];
            }
        }
    }
    while (n > 0){
        cout << trace[n];
        n -= cost[trace[n]];
    }
}
