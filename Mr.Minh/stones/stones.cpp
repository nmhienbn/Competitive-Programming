#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL);
#define NunuAndWillump "stones"
const int maxn = 405;

using namespace std;

int n, l[maxn][maxn];
ll a[maxn], dp[maxn][maxn];

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i], a[i] += a[i-1], l[i][i] = i;
    fi(i, 1, n-1) dp[i][i+1] = a[i+1] - a[i-1], l[i][i+1] = i;
    fid(i, n, 1){
        fi(j, i+2, n){
            dp[i][j] = 1e18;
            fi(k, l[i][j-1], l[i+1][j]){
                if (dp[i][j] > dp[i][k] + dp[k+1][j]){
                    dp[i][j] = dp[i][k] + dp[k+1][j];
                    l[i][j] = k;
                }
            }
            dp[i][j] += a[j] - a[i-1];
        }
    }
    cout << dp[1][n];
}
