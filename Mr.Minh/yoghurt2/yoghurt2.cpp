#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "yoghurt2"
const int maxn = 25e4+5;
using namespace std;

int n, a[maxn], b[maxn], dp[maxn], pos[maxn], remain[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i];
    fi(i, 1, n) cin >> b[i];
    fi(i, 1, n) remain[i] = -1e9;
    if (a[1] >= b[1]) dp[1] = 1, pos[1] = 1, remain[1] = a[1]-b[1];
    fi(i, 2, n){
        int cnt = dp[i-1];
        if (remain[cnt] + a[i] - b[i] >= 0){
            dp[i] = cnt+1;
            remain[cnt+1] = max(remain[cnt+1], remain[cnt] + a[i] - b[i]);
            pos[cnt+1] = i;
        }
        else {
            dp[i] = cnt;
            if (remain[cnt] < remain[cnt-1] + a[i] - b[i]){
                remain[cnt] = remain[cnt-1] + a[i] - b[i];
                pos[cnt] = i;
            }
            else remain[cnt] += a[i];
        }
    }
    cout << dp[n] << '\n';
    fi(i, 1, dp[n]) cout << pos[i] << ' ';
}
