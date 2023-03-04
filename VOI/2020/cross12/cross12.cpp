#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "cross12"
const int maxn = 1e5 + 5;
using namespace std;

int n, m;
int a[maxn], f[105];
int dp[maxn];
bool kt[105];
string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, n) cin >> a[i], kt[a[i]] = 1;
    cin >> s;
    s = ' ' + s;
    fi(i, 1, 100) if (kt[i]){
        int cur = 0;
        while (cur <= m){
            int nex = cur + i;
            f[i]++;
            if (nex > m) break;
            while (s[nex] == '1') nex--;
            cur = nex;
        }
    }
    fi(i, 1, n) a[i] = f[a[i]];
    sort(a + 1, a + n + 1);
    dp[1] = a[1];
    dp[2] = a[2];
    fi(i, 3, n){
        dp[i] = min(dp[i - 1] + a[i] + a[1], dp[i - 2] + a[i] + a[1] + a[2] * 2);
    }
    cout << dp[n];
}
