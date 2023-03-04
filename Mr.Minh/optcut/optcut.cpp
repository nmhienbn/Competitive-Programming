#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL);
#define NunuAndWillump "optcut"
const int maxn = 2005;

using namespace std;

int n, m, a[maxn], dp[maxn][maxn], l[maxn][maxn];

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        cin >> a[i];
        a[i] += a[i-1];
        l[i][i] = i;
    }
    fi(j, 2, n){
        fid(i, j-1, 1){
            dp[i][j] = 1e9+5;
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
