#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "lights"
const int maxn = 16;
const ll maxr = 1e18;

using namespace std;

int n, k, m, a[5005], b[maxn];
ll dp[5005][1 << 10], L[5005][1 << 10], res = 1e18, maxt;

int new_sta(int i){
    return (i&(~(1 << (k-1)))) << 1;
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> k >> m;
    fi(i, 0, n-1){
        cin >> a[i];
    }
    fi(i, 0, n-1){
        fi(j, 0, (1 << k) - 1){
            dp[i][j] = maxr;
        }
    }
    fi(x, 0, n-1){
        maxt = 0;
        fi(i, 1, (1 << k) - 1){
            L[x][i] = (i&1)*a[x];
            if (x > 0) L[x][i] += L[x-1][i >> 1];
            if (x == k-1) dp[x][i] = L[x][i];
            maxt = max(maxt, L[x][i]);
        }
        if (x >= k-1 && maxt < m){
            cout << "No solution";
            return 0;
        }
    }
    fi(x, k, n-1){
        fi(i, 1, (1 << k) - 1){
            int t = new_sta(i);
            fi(j, 0, 1){
                if (L[x][t|j] >= m){
                    dp[x][t|j] = min(dp[x][t|j], dp[x-1][i] + j*a[x]);
                }
            }
        }
    }
    cout << *min_element(dp[n-1]+1, dp[n-1] + (1 << k));
}
