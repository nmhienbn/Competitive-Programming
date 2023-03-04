#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "cargroup"
const int maxn = 1005;

using namespace std;

int n, P, L;
int w[maxn], v[maxn];
double t[maxn], dp[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> P >> L;
    fi(i, 1, n) cin >> w[i] >> v[i];
    double u = L;
    fi(i, 1, n) t[i] = u / v[i];
    fi(i, 1, n){
        dp[i] = 1e9;
        int weight = 0;
        double tg = t[i];
        fid(j, i, 1){
            weight += w[j];
            if (weight > P) break;
            tg = max(tg, t[j]);
            dp[i] = min(dp[i], dp[j - 1] + tg);
        }
    }
    cout << fixed << setprecision(2) << dp[n];
}
