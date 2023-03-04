#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "mincut"
const int maxn = 1005;
using namespace std;

int m, n, k;
ll a[maxn][maxn];

ll get(const int& u, const int& v, const int& i, const int& j){
    return a[i][j] + a[u - 1][v - 1] - a[u - 1][j] - a[i][v - 1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    //freopen(Irelia".inp", "r", stdin);
    //freopen(Irelia".out", "w", stdout);
    cin >> m >> n >> k;
    fi(i, 1, m) fi(j, 1, n){
        cin >> a[i][j];
        a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
    }
    fi(rep, 1, k){
        int x, y, u, v, d, c;
        ll ans = 1e18;
        cin >> x >> y >> u >> v;
        d = x, c = u - 1;
        while (d <= c){
            int g = (d + c) >> 1;
            if (get(x, y, g, v) < get(g + 1, y, u, v)) d = g + 1;
            else c = g - 1;
        }
        ans = min({ans, get(c + 1, y, u, v) - get(x, y, c, v), get(x, y, d, v) - get(d + 1, y, u, v)});

        d = y, c = v - 1;
        while (d <= c){
            int g = (d + c) >> 1;
            if (get(x, y, u, g) < get(x, g + 1, u, v)) d = g + 1;
            else c = g - 1;
        }
        ans = min({ans, get(x, c + 1, u, v) - get(x, y, u, c), get(x, y, u, d) - get(x, d + 1, u, v)});

        cout << ans << '\n';
    }

}
